/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:03:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/16 20:42:23 by jiskim           ###   ########.fr       */
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

t_ast	*subtree_rdr(t_type symbol, char *filename)
{
	t_ast	*new;
	t_type	io_type;

	if (symbol == SYMBOL_HERE)
		io_type = IO_HERE;
	else
		io_type = IO_RDR;
	new = new_node(RDR, NULL);
	new->left = new_node(io_type, NULL);
	new->right = NULL;
	new->left->left = new_node(symbol, NULL);
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
