/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/14 16:25:11 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(char *line)
{
	char	*start;
	char	*end;
	int		mask;

	start = line;
	end = start;
	mask = 0;
	while (*start)
	{
		while (*start && ft_strchr("\t\n\v\f\r ", *start))
			start++;
		end = start;
		if (ft_strchr("'\"", *start))
			mask |= (*start & 1);
		while (*end && !ft_strchr("\t\n\v\f\r ", *end))
		{
			end++;
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
		printf("%s\n", ft_substr(start, 0, end - start));
		start = end;
	}
	if (mask > 0)
		ft_putendl_fd("Syntax error", 2);
	// syntax
	// heredoc
	// tree
}
