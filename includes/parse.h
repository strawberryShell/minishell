/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:02:01 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/04 03:25:28 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

void	parse(t_box *box, char *line);
t_token	*new_token(char *data);
void	add_token(t_token **list, t_token *new);
void	free_token_list(t_token *list);
int		check_syntax(t_list *env_list, t_token **head, t_ast **ptr);
void	preorder_ast(t_ast *node, int index ,int height);
char	*remove_quote(t_list *env_list, t_ttype type, char *word);

#endif
