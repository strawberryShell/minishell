/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:24 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/15 16:09:01 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    initiate_env_lst(t_list **env_lst, char **envp)
{
	*env_lst = NULL;
	while(*envp)
    {
		ft_lstadd_back(env_lst, ft_lstnew(ft_strdup(*envp)));
		envp++;
    }
}

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

void	builtin_env(t_list *env_lst)
{
	if (!env_lst)
		return ;
	while(env_lst)
	{
		if (ft_strchr(env_lst->content, '='))
			printf("%s\n", (char*)env_lst->content);
		env_lst = env_lst->next;
	}
}
