/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:02:01 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/15 20:42:24 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structure.h"

void	parse(char *line);

t_token	*new_token(char *data);
void	add_token(t_token **list, t_token *new);
void	print_token(t_token *list);

#endif
