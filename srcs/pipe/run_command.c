/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:00:24 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 14:44:27 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  void    close_pipes(t_cmd *prev_cmd)
{
	if (prev_cmd)
	{
		ft_close(prev_cmd->fds[RD_FD]);
		ft_close(prev_cmd->fds[WR_FD]);
	}
}

static	t_cmd	*get_new_tcmd(t_box *box)
{
	t_cmd	*new_tcmd;

	new_tcmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	new_tcmd->argv = (char **)ft_calloc(1, sizeof(char *));
	ft_lstadd_back(&(box->cmd_lst), ft_lstnew(new_tcmd));
	return (new_tcmd);
}

void	run_command(t_box *box, t_ast *tree)
{	
	t_cmd	*prev_cmd;
	t_cmd	*curr_cmd;

	if (tree)
	{
		prev_cmd = (t_cmd*)(ft_lstlast(box->cmd_lst)->content);
		curr_cmd = get_new_tcmd(box);
		// builtin 한개일때 또는 cmd가 아예 없을때 처리 : 포크안뜨고 처리한다.
		if (tree->right)
			ft_pipe(curr_cmd->fds);
		curr_cmd->pid = ft_fork();
		if (!curr_cmd->pid)
		{
			connect_pipes(prev_cmd, curr_cmd);
			adjust_command(box, tree->left);	
			execute_command(box, tree->left->data);
		}
		close_pipes(prev_cmd);
		run_command(box, tree->right);
	}
	else
		// wait for children and set exit code
		return ;
}
