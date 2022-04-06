/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:02:01 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 01:01:35 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	parse(char *line);
t_token	*new_token(char *data);
void	add_token(t_token **list, t_token *new);
void	free_token_list(t_token *list);
int		check_syntax(t_token **head, t_ast **ptr);
void	preorder_ast(t_ast *node, int index, int height);
char	*remove_quote(t_ttype type, char *word);

#endif
