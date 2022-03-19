/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:00:24 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/19 23:41:15 by sehhong          ###   ########.fr       */
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

static	t_cmd	*get_new_tcmd(void)
{
	t_cmd	*ret_tcmd;

	ret_tcmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	ret_tcmd->argv = (char **)ft_calloc(1, sizeof(char *));
	return (ret_tcmd);
}

void	run_command(t_box *box, t_ast *tree)
{	
	t_cmd	*prev_cmd;
	t_cmd	*curr_cmd;

	if (tree)
	{
		prev_cmd = ft_lstlast(box->cmd_lst);
		curr_cmd = get_new_tcmd();
		ft_lstadd_back(&(box->cmd_lst), ft_lstnew(curr_cmd));
		// builtin 한개일때 처리
		if (tree->right)
			ft_pipe(curr_cmd->fds);
		curr_cmd->pid = ft_fork();
		if (!curr_cmd->pid)
		{
			connect_pipes(prev_cmd, curr_cmd);
			adjust_command(box, tree->left);	
			execute_command();
		}
		close_pipes(prev_cmd);
		run_command(box, tree->right);
	}
	else
		// wait for children and set exit code
		return ;
}
