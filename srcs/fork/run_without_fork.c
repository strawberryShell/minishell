/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_without_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:32:27 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 16:02:12 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// builtin 한개일때 또는 cmd가 아예 없을때 처리 : 포크안뜨고 처리한다.
void	run_without_fork(t_box *box, t_ast *cmd, t_ctype cmd_type)
{
	char	**argv;
	int		stdin_backup;
	int		stdout_backup;
	
	stdin_backup = dup(STDIN_FILENO);
	stdout_backup = dup(STDOUT_FILENO);
	redirect_files(cmd->left);
	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = cmd->right->left->data;
	make_argv(&argv, cmd->right->right);
	// fd 원상복귀
	ft_dup2(stdin_backup, STDIN_FILENO);
	ft_close(stdin_backup);
	ft_dup2(stdout_backup, STDOUT_FILENO);
	ft_close(stdout_backup);
	if (cmd_type == NONE)
		box->status = EXIT_SUCCESS;
	else
		box->status = execute_builtin(box->env_lst, argv, cmd_type);
}