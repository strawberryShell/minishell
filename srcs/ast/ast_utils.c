/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/24 21:00:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ast	*new_node(t_type type, char *data)
{
	t_ast	*new;

	new = ft_calloc(1, sizeof(t_ast));
	new->type = type;
	new->data = data;
	return (new);
}

t_ast	*subtree_pipeseq(void)
{
	t_ast	*new;

	new = new_node(PIPESEQ, NULL);
	new->left = new_node(CMD, NULL);
	new->right = NULL;
	return (new);
}

t_ast	*subtree_rdr(t_ttype symbol_ttype, char *symbol, char *filename)
{
	t_ast	*new;
	t_type	io_type;
	t_type	symbol_type;

	if (symbol_ttype == SYMBOL_HERE)
	{
		io_type = IO_HERE;
		symbol_type = SYMBOL_DL;
	}
	else
	{
		io_type = IO_RDR;
		if (*symbol == '<')
			symbol_type = SYMBOL_L;
		else if (!ft_strncmp(symbol, ">", 2))
			symbol_type = SYMBOL_G;
		else
			symbol_type = SYMBOL_DG;
	}
	new = new_node(RDR, NULL);
	new->left = new_node(io_type, NULL);
	new->right = NULL;
	new->left->left = new_node(symbol_type, NULL);
	new->left->right = new_node(FNAME, filename);
	return (new);
}

t_ast	*subtree_simple_command(t_type cmd, char *word)
{
	t_ast	*new;
	t_type	type;

	if (cmd == SIMPLE_CMD)
		type = NAME;
	else
		type = ARG;
	new = new_node(cmd, NULL);
	new->left = new_node(type, word);
	new->right = NULL;
	return (new);
}

void	preorder_ast(t_ast *node, int index)
{
	if (node == NULL)
		return ;
	printf("(%d, (type = %d, data = %s)\n", index, node->type, node->data);
	preorder_ast(node->left, index * 2);
	preorder_ast(node->right, index * 2 + 1);
}
