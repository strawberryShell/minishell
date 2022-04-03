/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:45:00 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/03 00:59:45 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  t_cmd *get_last_cmd(t_box *box)
{
    t_list	*prev_list;
    t_cmd	*last_cmd;

    prev_list = ft_lstlast(box->cmd_list);
    if (prev_list)
		last_cmd = (t_cmd*)(prev_list->content);
    else   
		last_cmd = NULL;
	return (last_cmd);
}

static	void	free_cmd_list(t_box *box)
{
	t_list	*curr_cmd;
	
	if (!box->cmd_list)
		return ;
	while (box->cmd_list)
	{
		curr_cmd = box->cmd_list;
		box->cmd_list = (box->cmd_list)->next;
		free_ptr((void**)&(curr_cmd->content));
		free_ptr((void**)&curr_cmd);
	}
}

void	read_ast(t_box *box, t_ast *tree)
{	
	t_cmd	*prev_cmd;
	int		ret;

	if (tree)
	{
		prev_cmd = get_last_cmd(box);
		ret = need_fork(prev_cmd, tree);
		if (ret != -1)
		{	
			run_without_fork(box, tree->left, (t_ctype)ret);
			return ;
		}
		fork_child(box, tree, prev_cmd);
		read_ast(box, tree->right);
	}
	else
	{	
		wait_children(box);
		free_cmd_list(box);
		return ;
	}
}
