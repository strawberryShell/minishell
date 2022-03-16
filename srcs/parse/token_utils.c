/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:00:14 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/16 20:34:30 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief
 *
 * @param data nullable
 * @param type WORD, SYMBOL
 * @return t_token*
 *
 * << >> < > | 그 외
 */
t_token	*new_token(char *data)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (ft_strchr("<>|", *data))
	{
		if (*data == '|')
			new->type = PIPE;
		else if (data[0] == '<' && data[1] == '<')
			new->type = SYMBOL_HERE;
		else
			new->type = SYMBOL;
		free(data);
	}
	else
	{
		new->type = WORD;
		new->data = data;
	}
	return (new);
}

void	add_token(t_token **list, t_token *new)
{
	t_token	*tmp;

	tmp = *list;
	if (!*list)
	{
		*list = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	token_iterate(t_token *list, void (*f)(t_token *))
{
	while (list)
	{
		printf("(%d %s)->", list->type, list->data);
		f(list);
		list = list->next;
	}
}
