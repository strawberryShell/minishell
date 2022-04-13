/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:37:42 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/13 18:00:35 by jiskim           ###   ########.fr       */
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

static void	execute_general(char *cmd, char **argv)
{
	char	**new_envp;

	if (!ft_strncmp(".", cmd, 2) || !ft_strncmp("..", cmd, 3))
		exit_with_err(argv[0], "command not found", 127);
	else
	{
		cmd = find_abs_path(cmd);
		new_envp = make_envp();
		execve(cmd, argv, new_envp);
		if (errno == ENOENT)
			exit_with_err(argv[0], "command not found", 127);
		exit_with_err(argv[0], strerror(errno), EXIT_FAILURE);
	}
}

void	execute_command(t_ast *scmd)
{
	char		**argv;
	t_ctype		cmd_type;
	int			exit_code;

	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = scmd->left->data;
	make_argv(&argv, scmd->right);
	cmd_type = which_cmd_type(argv[0]);
	if (cmd_type == GENERAL)
		execute_general(scmd->left->data, argv);
	else if (cmd_type == NONE)
		exit(EXIT_SUCCESS);
	else
	{
		exit_code = execute_builtin(argv, cmd_type);
		exit(exit_code);
	}
}
