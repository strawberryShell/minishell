/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:37:42 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 21:49:41 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**make_envp(void)
{
	int		i;
	t_list	*ptr;
	char	**new_envp;

	ptr = g_box->env_list;
	new_envp = (char **)ft_calloc(ft_lstsize(ptr) + 1, sizeof(char *));
	i = 0;
	while (ptr)
	{
		new_envp[i] = (char *)(ptr->content);
		i++;
		ptr = ptr->next;
	}
	return (new_envp);
}

static void	execute_general(char *abs_path, char **argv)
{
	char	**new_envp;
	// int		i;

	// i = 0;
	//while (argv[i])
	//	ft_putendl_fd(argv[i++], 2);
	//ft_putendl_fd("-------------", 2);
	new_envp = make_envp();
	execve(abs_path, argv, new_envp);
	if (errno == ENOENT)
		exit_with_err(argv[0], "command not found", 127);
	exit_with_err(argv[0], strerror(errno), EXIT_FAILURE);
}

void	execute_command(t_ast *scmd)
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
		abs_path = find_abs_path(scmd->left->data);
		execute_general(abs_path, argv);
	}
	else if (cmd_type == NONE)
		exit(EXIT_SUCCESS);
	else
	{
		exit_code = execute_builtin(argv, cmd_type);
		exit(exit_code);
	}
}
