/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:51:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/26 18:21:24 by sehhong          ###   ########.fr       */
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

static	t_cmd	*get_new_tcmd(t_list **cmd_lst)
{
	t_cmd	*new_tcmd;

	new_tcmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	ft_lstadd_back(cmd_lst, ft_lstnew(new_tcmd));
	return (new_tcmd);
}

static	void	wait_children(t_box *box)
{
	int		status;
	int		last_status;
	pid_t	child_pid;
	pid_t	last_pid;

	last_pid = ((t_cmd*)(ft_lstlast(box->cmd_lst)->content))->pid;
	child_pid = 0;
	while (child_pid != -1)
	{
		child_pid = waitpid(-1, &status, 0);
		if (child_pid == last_pid)
			last_status = status;
	}
	if (WIFEXITED(last_status))
		box->status = WEXITSTATUS(last_status);
	else if (WIFSIGNALED(last_status))
		box->status = WTERMSIG(last_status);
	else
		box->status = EXIT_FAILURE;
}

void	build_pipes(t_box *box, t_ast *tree)
{	
	t_list	*prev_list;
	t_cmd	*prev_cmd;
	t_cmd	*curr_cmd;

	if (tree)
	{
		prev_list = ft_lstlast(box->cmd_lst);
		if (prev_list)
			prev_cmd = (t_cmd*)(prev_list->content);
		else
			prev_cmd = NULL;
		curr_cmd = get_new_tcmd(&(box->cmd_lst));
		// builtin 한개일때 또는 cmd가 아예 없을때 처리 : 포크안뜨고 처리한다.
		if (tree->right)
			ft_pipe(curr_cmd->fds);
		curr_cmd->pid = ft_fork();
		if (!curr_cmd->pid)
		{
			connect_pipes(prev_cmd, curr_cmd);
			redirect_files(box, tree->left->left);
			run_command(box, tree->left->right);
		}
		close_pipes(prev_cmd);
		build_pipes(box, tree->right);
	}
	else
	{	
		wait_children(box);
		return ;
	}
}
