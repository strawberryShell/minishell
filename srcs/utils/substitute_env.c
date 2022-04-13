/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:16:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/13 15:21:04 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*substitute_env(char **start, char *str)
{
	char	*end;
	char	*env;
	char	*value;
	char	*tmp;

	end = ++(*start);
	if (ft_isdigit(*end) || ft_strchr("!#$*-?@_", *end))
		end++;
	else
		while (*end && (ft_isalnum(*end) || *end == '_'))
			end++;
	env = ft_substr(*start, 0, end - *start);
	*start = --end;
	value = get_env(env);
	if (!value)
		value = "";
	if (!str)
		str = ft_calloc(1, 1);
	tmp = ft_strjoin(str, value);
	if (!ft_strncmp(env, "?", 2))
		free(value);
	free(env);
	free(str);
	return (tmp);
}
