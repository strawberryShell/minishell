/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/14 21:24:57 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_str(char *start, char *end)
{
	char	*result;
	int		i;
	char	quote;

	result = (char *)ft_calloc((end - start) + 1, 1);
	i = 0;
	quote = 0;
	while (start != end)
	{
		if (ft_strchr("'\"", *start))
		{
			if (!quote)
				quote = *start;
			else if (quote == *start)
				quote = 0;
			else
				result[i++] = *start;
		}
		else
			result[i++] = *start;
		start++;
	}
	return (result);
}

void	parse(char *line)
{
	char	*start;
	char	*end;
	char	quote;

	start = line;
	end = start;
	quote = 0;
	while (*start)
	{
		while (*start && ft_strchr("\t\n\v\f\r ", *start))
			start++;
		end = start;
		while (*end && !ft_strchr("\t\n\v\f\r ", *end))
		{
			if (quote == 0 && ft_strchr("'\"", *end))
				quote = *end;
			end++;
			if (quote)
			{
				while (*end && *end != quote)
					end++;
				if (*end == quote)
				{
					end++;
					quote = 0;
				}
			}
			if (*start == '|')
				break;
			if (ft_strchr("<>", *start))
			{
				if (*start == *end)
					end++;
				break;
			}
			if (ft_strchr("<>|", *end))
				break;
		}
		printf("%s\n", make_str(start, end));
		start = end;
	}
	if (quote)
		ft_putendl_fd("Syntax error", 2);
	// syntax
	// heredoc
	// tree
}
