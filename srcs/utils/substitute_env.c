/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:16:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 00:18:09 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*substitute_env(t_list *env_list, char **start, char *str)
{
	char	*end;
	char	*env;
	char	*value;

	end = ++(*start);
	if (ft_isdigit(*end) || ft_strchr("!#$*-?@_", *end))
		end++;
	else
	{
		while (*end && (ft_isalnum(*end) || *end == '_'))
			end++;
	}
	env = ft_substr(*start, 0, end - *start);
	*start = --end;
	value = get_env(env_list, env);
	free(env);
	if (!value)
		value = "";
	if (!str)
		str = "";
	return (ft_strjoin(str, value));
}
