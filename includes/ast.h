/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:32:36 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/31 00:21:34 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

#include "structure.h"

t_ast	*subtree_pipeseq(void);
t_ast	*subtree_rdr(char *symbol, char *filename);
t_ast	*subtree_simple_command(t_type cmd, char *word);
void	preorder_ast(t_ast *node, int index);
void	free_ast(t_ast *node);
void	read_ast(t_box *box, t_ast *tree);

#endif
