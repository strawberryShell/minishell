/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_without_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:32:27 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/31 14:35:11 by sehhong          ###   ########.fr       */
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

static	void	exit_without_fork(t_box *box, char **argv)
{
	int	if_exit;

	if_exit = 1;
	ft_putendl_fd("exit", STDERR_FILENO);
	box->status = ft_exit(argv, &if_exit);
	// 특정 exit의 상황일 경우, minishell process를 끝낸다.
	if (if_exit)
	{
		delete_tmpfiles();
		exit(box->status);
	}	
}

// builtin 한개일때 또는 cmd가 아예 없을때 처리 : 포크안뜨고 처리한다.
void	run_without_fork(t_box *box, t_ast *cmd, t_ctype cmd_type)
{
	char	**argv;
	int		stdin_backup;
	int		stdout_backup;

	backup_std_fds(&stdin_backup, &stdout_backup);
	redirect_files(cmd->left);
	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = cmd->right->left->data;
	make_argv(&argv, cmd->right->right);
	if (cmd_type == NONE)
		box->status = EXIT_SUCCESS;
	else if (cmd_type == EXIT)
		exit_without_fork(box, argv);
	else
		box->status = execute_builtin(box->env_lst, argv, cmd_type);
	recover_std_fds(stdin_backup, stdout_backup);
}
