/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:47:40 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 20:08:22 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc(char *prev, char word)
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
