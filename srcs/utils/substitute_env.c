/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:16:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 11:56:49 by sehhong          ###   ########.fr       */
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
		str = "";
	tmp = ft_strjoin(str, value);
	if (!ft_strncmp(env, "?", 2))
		free(value);
	free(env);
	if (ft_strncmp(str, "", 1))
		free(str);
	return (tmp);
}
