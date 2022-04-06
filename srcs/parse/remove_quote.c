/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:22:52 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 00:17:44 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_realloc(char *prev, char word)
{
	char	*new;
	int		len;
	int		i;

	if (!prev)
		len = 0;
	else
		len = ft_strlen(prev);
	new = ft_calloc(len + 2, 1);
	i = 0;
	if (prev)
	{
		while (prev[i])
		{
			new[i] = prev[i];
			i++;
		}
		free(prev);
	}
	new[i] = word;
	return (new);
}

static int	check_param(char *str)
{
	str++;
	return (*str && (ft_isalnum(*str) || ft_strchr("!#$*-?@_", *str)));
}

char	*remove_quote(t_list *env_list, t_ttype type, char *word)
{
	char	*result;
	char	quote;

	result = NULL;
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
				result = substitute_env(env_list, &word, result);
			else
				result = ft_realloc(result, *word);
		}
		word++;
	}
	return (result);
}
