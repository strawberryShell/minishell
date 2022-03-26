/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:24 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/26 17:20:08 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_list *env_lst)
{
	if (!env_lst)
		return (EXIT_SUCCESS);
	while(env_lst)
	{
		if (ft_strchr(env_lst->content, '='))
			printf("%s\n", (char*)env_lst->content);
		env_lst = env_lst->next;
	}
	return (EXIT_SUCCESS);
}
