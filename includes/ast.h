/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:32:36 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/01 15:47:19 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

t_ast	*subtree_pipeseq(void);
t_ast	*subtree_rdr(char *symbol, char *filename);
t_ast	*subtree_simple_command(t_type cmd, char *word);
void	preorder_ast(t_ast *node, int index ,int height);
void	free_ast(t_ast *node);
void	read_ast(t_box *box, t_ast *tree);

#endif
