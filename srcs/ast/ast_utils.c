/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/31 01:25:15 by jiskim           ###   ########.fr       */
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

void	preorder_ast(t_ast *node, int index ,int height)
{
	if (node == NULL)
		return ;
	printf("(%d, (%d, %s)\n", index, node->type, node->data);
	preorder_ast(node->left, index * 2, height + 1);
	preorder_ast(node->right, index * 2 + 1, height + 1);
}
