/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:45:00 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 18:20:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_cmd	*get_last_cmd(void)
{
	t_list	*prev_list;
	t_cmd	*last_cmd;

	prev_list = ft_lstlast(g_box->cmd_list);
	if (prev_list)
		last_cmd = (t_cmd *)(prev_list->content);
	else
		last_cmd = NULL;
	return (last_cmd);
}

static	void	free_cmd_list(void)
{
	t_list	*curr_cmd;

	if (!g_box->cmd_list)
		return ;
	while (g_box->cmd_list)
	{
		curr_cmd = g_box->cmd_list;
		g_box->cmd_list = (g_box->cmd_list)->next;
		free_ptr((void **)&(curr_cmd->content));
		free_ptr((void **)&curr_cmd);
	}
}

void	read_ast(t_ast *tree)
{
	t_cmd	*prev_cmd;
	int		ret;

	if (tree)
	{
		prev_cmd = get_last_cmd();
		ret = need_fork(prev_cmd, tree);
		if (ret != -1)
		{
			run_without_fork(tree->left, (t_ctype)ret);
			return ;
		}
		fork_child(tree, prev_cmd);
		read_ast(tree->right);
	}
	else
	{
		on_echoctl();
		signal(SIGINT, ignore_signal);
		wait_children();
		free_cmd_list();
		return ;
	}
}
