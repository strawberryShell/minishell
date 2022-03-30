/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/31 00:24:18 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ast(t_ast *node)
{
	if (node == NULL)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	if (node->data && node->type != CMD)
	{
		free(node->data);
		node->data = NULL;
	}
	free(node);
	node = NULL;
}

void	preorder_ast(t_ast *node, int index)
{
	if (node == NULL)
		return ;
	printf("(%d, (type = %d, data = %s)\n", index, node->type, node->data);
	preorder_ast(node->left, index * 2);
	preorder_ast(node->right, index * 2 + 1);
}
