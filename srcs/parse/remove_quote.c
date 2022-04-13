/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:22:52 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/13 17:24:16 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_param(char *str)
{
	str++;
	return (*str && (ft_isalnum(*str) || ft_strchr("!#$*-?@_", *str)));
}

char	*remove_quote(t_ttype type, char *word)
{
	char	*result;
	char	quote;

	result = ft_calloc(1, 1);
	quote = 0;
	while (*word)
	{
		if (!quote && ft_strchr("'\"", *word))
			quote = *word;
		else if (quote == *word)
			quote = 0;
		else
		{
			if (type != SYMBOL_HERE && *word == '$' && quote != '\''
				&& check_param(word))
				result = substitute_env(&word, result);
			else
				result = ft_realloc(result, *word);
		}
		word++;
	}
	return (result);
}
