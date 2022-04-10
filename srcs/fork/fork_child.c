/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:51:54 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 19:11:52 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	close_pipes(t_cmd *prev_cmd)
{
	if (prev_cmd)
	{
		ft_close(prev_cmd->fds[RD_FD]);
		ft_close(prev_cmd->fds[WR_FD]);
	}
}

static	t_cmd	*get_new_cmd(void)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	new_cmd->fds[RD_FD] = -1;
	new_cmd->fds[WR_FD] = -1;
	return (new_cmd);
}

void	fork_child(t_ast *tree, t_cmd *prev_cmd)
{
	t_cmd	*curr_cmd;

	curr_cmd = get_new_cmd();
	ft_lstadd_back(&(g_box->cmd_list), ft_lstnew(curr_cmd));
	if (tree->right)
		ft_pipe(curr_cmd->fds);
	signal(SIGQUIT, ignore_signal);
	curr_cmd->pid = ft_fork();
	if (!curr_cmd->pid)
	{
		connect_pipes(prev_cmd, curr_cmd);
		redirect_files(tree->left->left);
		execute_command(tree->left->right);
	}
	close_pipes(prev_cmd);
}
