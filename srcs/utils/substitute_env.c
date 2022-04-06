/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 03:16:44 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 00:51:25 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*substitute_env(char **start, char *str)
{
	char	*end;
	char	*env;
	char	*value;

/**
 * @brief 숫자거나 special varable이면 한글자까지만 끊는다.
 */
	end = ++(*start);
	if (ft_isdigit(*end) || ft_strchr("!#$*-?@_", *end))
		end++;
	else
	{
		/**
		 * @brief 알파벳, 숫자, _가 아닌 문자를 만나면 끊는다. 언더바 정말 .똘아이네요
		 */
		while (*end && (ft_isalnum(*end) || *end == '_'))
			end++;
	}
	env = ft_substr(*start, 0, end - *start);
	*start = --end;
	value = get_env(env);
	free(env);
	if (!value)
		value = "";
	if (!str)
		str = "";
	return (ft_strjoin(str, value));
}
