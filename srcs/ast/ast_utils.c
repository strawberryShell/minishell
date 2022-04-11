/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/10 17:35:53 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ast(t_ast *node)
{
	if (node == NULL)
		return ;
	if (node->type == IO_HERE)
		unlink(node->right->data);
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
