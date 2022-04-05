/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:37:42 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 14:22:25 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_envp(t_list *env_list)
{
	int		i;
	char	**new_envp;

	new_envp = (char **)ft_calloc(ft_lstsize(env_list) + 1, sizeof(char *));
	i = 0;
	while (env_list)
	{
		new_envp[i] = (char *)(env_list->content);
		i++;
		env_list = env_list->next;
	}
	return (new_envp);
}

static void	execute_general(t_list *env_list, char *abs_path, char **argv)
{
	int		i;
	char	**new_envp;

	ft_putendl_fd(abs_path, 2);
	i = 0;
	while (argv[i])
		ft_putendl_fd(argv[i++], 2);
	ft_putendl_fd("-------------", 2);
	new_envp = make_envp(env_list);
	execve(abs_path, argv, new_envp);
	if (errno == ENOENT)
		exit_with_err(argv[0], "command not found", 127);
	exit_with_err(argv[0], strerror(errno), EXIT_FAILURE);
}

void	execute_command(t_box *box, t_ast *scmd)
{
	char		*abs_path;
	char		**argv;
	t_ctype		cmd_type;
	int			exit_code;

	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = scmd->left->data;
	make_argv(&argv, scmd->right);
	cmd_type = which_cmd_type(argv[0]);
	if (cmd_type == GENERAL)
	{
		abs_path = find_abs_path(box->env_list, scmd->left->data);
		execute_general(box->env_list, abs_path, argv);
	}
	else if (cmd_type == NONE)
		exit(EXIT_SUCCESS);
	else
	{	
		exit_code = execute_builtin(box, argv, cmd_type);
		exit(exit_code);
	}
}
