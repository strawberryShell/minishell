/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:00:14 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/31 01:46:08 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief
 *
 * @param data nullable
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
		new->data = data;
	}
	else
	{
		new->type = WORD;
		new->data = data;
	}
	return (new);
}

/**
 * 수정된 코드는 모든 data를 그대로 사용하지 않으므로 무조건 free 해줍니다.
 * WORD type도 ast에 들어갈 때 realloc으로 새로운 문자열이 만들어집니다.
 */
void	free_token_list(t_token *list)
{
	t_token *tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list->data);
		list->data = NULL;
		free(list);
		list = tmp;
	}
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
