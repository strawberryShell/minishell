/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:02:01 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/27 23:11:00 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structure.h"

void	parse(char *line);

t_token	*new_token(char *data);
void	add_token(t_token **list, t_token *new);
t_ast	*syntax_analysis(t_token *list);
void	free_token_list(t_token *list);
int		check_syntax(t_token **head, t_ast **ptr);

#endif
