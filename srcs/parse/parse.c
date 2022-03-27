/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/28 02:37:17 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(char *line)
{
	char	*start;
	char	*end;
	char	quote;
	t_token	*token_list;
	t_ast	*root;

	start = line;
	end = start;
	quote = 0;
	token_list = NULL;
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
			if (ft_strchr("<>|", *start))
			{
				if (*start == *end && *start != '|')
					end++;
				break;
			}
			if (ft_strchr("<>|", *end))
				break;
		}
		if (start < end)
			add_token(&token_list, new_token(ft_substr(start, 0, (end - start))));
		start = end;
	}
	if (quote)
		ft_putendl_fd("Syntax error", 2);
	root = syntax_analysis(token_list);
	free_token_list(token_list);
	free_ast(root);
}
