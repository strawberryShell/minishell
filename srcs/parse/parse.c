/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/15 20:41:51 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_token	*make_str(char *start, char *end)
// {
// 	char	*result;
// 	int		i;
// 	char	quote;
// 	t_ttype	type;

// 	result = (char *)ft_calloc((end - start) + 1, 1);
// 	i = 0;
// 	quote = 0;
// 	type = WORD;
// 	if (ft_strchr("<>", *start))
// 		type = SYMBOL;
// 	while (start != end)
// 	{
// 		if (ft_strchr("'\"", *start))
// 		{
// 			if (!quote)
// 			{
// 				if (quote == '\'')
// 					type = SQ_WORD;
// 				quote = *start;
// 			}
// 			else if (quote == *start)
// 				quote = 0;
// 			else
// 				result[i++] = *start;
// 		}
// 		else
// 			result[i++] = *start;
// 		start++;
// 	}
// 	return (new_token(result, type)); //return new node(string, type)
// }

void	parse(char *line)
{
	char	*start;
	char	*end;
	char	quote;
	t_token	*token_list;

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
		add_token(&token_list, new_token(ft_substr(start, 0, (end - start))));
		start = end;
	}
	print_token(token_list);
	if (quote)
		ft_putendl_fd("Syntax error", 2);
	// syntax
	// heredoc
	// tree
}
