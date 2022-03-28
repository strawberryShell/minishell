/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:32:36 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/24 20:58:12 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

t_ast	*subtree_pipeseq(void);
t_ast	*subtree_rdr(t_ttype symbol_type, char *symbol, char *filename);
t_ast	*subtree_simple_command(t_type cmd, char *word);
void	preorder_ast(t_ast *node, int index);

#endif
