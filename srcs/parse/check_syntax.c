/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:55 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/24 21:00:37 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_syntax(t_token **head, t_ast **ptr)
{
	//(type, data) 에휴;
	// int	mask;
	//구문이 완성되면 트리 (SYMBOL -> 2개 확정. 나머지 -> 노답임)

	// if (token->type == SYMBOL_HERE)
	// {
	// 	//heredoc 처리하는 함수
	// }
	// else if (token->type == PIPE)
	// {
	// 	//quote벗기면서 환경변수 적용
	// }
	t_ast	*tmp;
	t_token	*token = *head;

	tmp = *ptr;
	if (token->type == PIPE)
	{
		(*ptr)->right = subtree_pipeseq();
		*ptr = (*ptr)->right->left;
	}
	else if (token->type == SYMBOL || token->type == SYMBOL_HERE)
	{
		while (tmp->left != NULL)
			tmp = tmp->left;
		tmp->left = subtree_rdr(token->type, token->data, token->next->data);
		token = token->next;
	}
	else
	{
		while (tmp->right != NULL)
			tmp = tmp->right;
		if (tmp->type == CMD)
			tmp->right = subtree_simple_command(SIMPLE_CMD, token->data);
		else
			tmp->right = subtree_simple_command(ARGV, token->data);
	}
	*head = token;
}
