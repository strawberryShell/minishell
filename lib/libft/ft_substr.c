/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:19:31 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 03:14:58 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*tmp;
	size_t	result_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]) || len < 0)
		result_len = ft_strlen(&s[start]);
	else
		result_len = len;
	result = (char *)ft_calloc(result_len + 1, 1);
	s += start;
	tmp = result;
	while (len-- && *s)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
