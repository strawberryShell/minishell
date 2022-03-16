/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:55 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/16 20:47:51 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_syntax(t_token *head)
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

	t_ast	*root = subtree_pipeseq();
	t_ast	*ptr = root;
	t_ast	*tmp = ptr;
	t_token	*token = head;


	if (token->type == PIPE)
	{
		ptr->right = subtree_pipeseq();
		ptr = ptr->right;
	}
	else if (token->type == SYMBOL || token->type == SYMBOL_HERE)
	{
		tmp = ptr;
		while (tmp->left != NULL)
			tmp = tmp->left;
		tmp->left = subtree_rdr(token->type, token->next->data);
		token = token->next;
	}
}
