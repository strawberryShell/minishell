/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/12 19:05:40 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse(char *line)
{
	char	*start;
	char	*end;
	int

	line = start;
	end = start;
	while (*start)
	{
		while (*end || ft_isprint)
			end++;
		if (complete)
			break;
		start = end;
	}
	// syntax
	// heredoc
	// tree
}
