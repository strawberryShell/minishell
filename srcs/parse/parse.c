/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/12 21:26:08 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_str(char *start, char *end)
{

}

void	parse(char *line)
{
	char	*start;
	char	*end;
	int		mask;

	line = start;
	end = start;
	mask = 0;
	while (*start)
	{
		while (*start && ft_strchr("\t\n\v\f\r ", *start))
			start++;
		if (ft_strchr("<>", *start))
			mask |= 1;
		while (*end && !ft_strchr("\t\n\v\f\r ", *end))
		{
			if (mask & 1 && (*end != *(end + 1)))
				break;
			end++;
		}
		end = start;
	}
	// syntax
	// heredoc
	// tree
}
