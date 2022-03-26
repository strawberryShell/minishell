/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:23:26 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/27 00:06:42 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 환경변수(key)에 상응하는 value를 반환하는 함수 
char	*get_env_value(t_list *env_lst, char *key)
{
	while(env_lst)
	{
		if (is_same_key(env_lst->content, key))
			return (ft_strchr(env_lst->content, '=') + 1);
		env_lst = env_lst->next;
	}
	return (NULL);
}

int	is_same_key(char *str, char *key)
{
	int	key_len;

	key_len = ft_strlen(key);
	if (!ft_strncmp(str, key, key_len) && str[key_len] == '=')
		return (1);
	return (0);
}

int	is_special_var(char *var)
{
	char	*sp_str;

	sp_str = "!#$@?-*_0123456789";
	if (*var == '$')
	{
		var++;
		while (*sp_str)
		{
			if (*sp_str == *var)
				return (1);
			sp_str++;
		}
	}
	return (0);
}
