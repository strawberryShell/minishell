/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:37:42 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 16:21:30 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	**make_envp(t_list *env_lst)
{
	char	**new_envp;

	new_envp = (char **)ft_calloc(ft_lstsize(env_lst) + 1, sizeof(char *));
	while (env_lst)
	{
		*new_envp = (char *)(env_lst->content);
		new_envp++;
		env_lst = env_lst->next;
	}
	return (new_envp);
}

static	void	execute_general(t_list *env_lst, char *abs_path, char **argv)
{
	int	i;

	ft_putendl_fd(abs_path, 2);
	i = 0;
	while (argv[i])
		ft_putendl_fd(argv[i++], 2);
	ft_putendl_fd("-------------", 2);
	execve(abs_path, argv, make_envp(env_lst));
	if (errno == ENOENT)
		exit_with_err(argv[0], "command not found", 127);
	exit_with_err(argv[0], strerror(errno), EXIT_FAILURE);
}

void	execute_command(t_list *env_lst, t_ast *scmd)
{
	char	    *abs_path;
	char	    **argv;
    t_ctype   	cmd_type;
	int			exit_code;
	
	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = scmd->left->data;
	make_argv(&argv, scmd->right);
    cmd_type = which_cmd_type(argv[0]);
    if (cmd_type == GENERAL)
	{
		abs_path = find_abs_path(env_lst, scmd->left->data);
		execute_general(env_lst, abs_path, argv);
	}
	else if (cmd_type == NONE)
		exit(EXIT_SUCCESS);
	else
	{	
		exit_code = execute_builtin(env_lst, argv, cmd_type);
		exit(exit_code);
	}
}