/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:21:08 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/15 08:21:10 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	delete_target_node(t_list **env_lst, char *key)
{
	t_list	*curr;
	t_list	*del_node;

	curr = *env_lst;
	if (!*env_lst)
		return;
	// 첫번째 노드가 찾는 key의 노드일때 -> 지운다
	if (is_same_key(curr->content, key))
	{
		env_lst = &(curr->next);
		free(curr->content);
		free(curr);
		return ;
	}
	while (curr->next)
	{
		if (is_same_key(curr->next->content, key))
		{
			del_node = curr->next;
			// 중간 노드가 찾는 key의 노드일때
			if (del_node->next)
				curr->next = del_node->next;
			// 마지막 노드가 찾는 key의 노드일때
			else
				curr->next = NULL;
			free(del_node->content);
			free(del_node);
			return ;
		}
		curr = curr->next;
	}
	// head_node->next == NULL이면 그냥 끝남
}

void	builtin_unset(t_list **env_lst, char **argv)
{
	char	*equal_ptr;
	
	argv++;
	while(*argv)
	{
		// 해당 문자열 유효한 key인가? 유효하지 않음 -> 에러메세지
		equal_ptr = ft_strchr(*argv, '=');
		if (equal_ptr)	// '='가 있음
			print_err_msg("unset", *argv, "invalid parameter name");
		// '='가 없음 (유효함) -> 해당 노드 찾아 지우기
		else
			delete_target_node(env_lst, *argv);
		argv++;
	}
}
