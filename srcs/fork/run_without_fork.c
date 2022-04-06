/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_without_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:32:27 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 00:59:33 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	backup_std_fds(int *stdin_fd, int *stdout_fd)
{
	*stdin_fd = dup(STDIN_FILENO);
	*stdout_fd = dup(STDOUT_FILENO);
}

static	void	recover_std_fds(int stdin_fd, int stdout_fd)
{
	ft_dup2(stdin_fd, STDIN_FILENO);
	ft_close(stdin_fd);
	ft_dup2(stdout_fd, STDOUT_FILENO);
	ft_close(stdout_fd);
}

static	void	exit_without_fork(t_ast *rdr, char **argv)
{
	int	if_exit;

	if_exit = 1;
	ft_putendl_fd("exit", STDERR_FILENO);
	g_box->exit_code = ft_exit(argv, &if_exit);
	if (if_exit)
	{
		delete_tmpfile(rdr);
		exit(g_box->exit_code);
	}	
}

void	run_without_fork(t_ast *cmd, t_ctype cmd_type)
{
	char	**argv;
	int		stdin_backup;
	int		stdout_backup;

	backup_std_fds(&stdin_backup, &stdout_backup);
	redirect_files(cmd->left);
	if (cmd_type == NONE)
	{
		g_box->exit_code = EXIT_SUCCESS;
		recover_std_fds(stdin_backup, stdout_backup);
		return ;
	}
	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = cmd->right->left->data;
	make_argv(&argv, cmd->right->right);
	if (cmd_type == EXIT)
		exit_without_fork(cmd->left, argv);
	else
		g_box->exit_code = execute_builtin(argv, cmd_type);
	free_ptr((void **)&argv);
	recover_std_fds(stdin_backup, stdout_backup);
}
