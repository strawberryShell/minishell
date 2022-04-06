/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:24 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 00:58:58 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **argv)
{
	if (argv[1])
	{
		if (is_option(argv[1], "env"))
			return (EXIT_FAILURE);
		print_err("env", argv[1], strerror(ENOENT));
		return (127);
	}
	if (!g_box->env_list)
		return (EXIT_SUCCESS);
	while (g_box->env_list)
	{
		if (ft_strchr(g_box->env_list->content, '='))
			ft_putendl_fd((char *)g_box->env_list->content, STDOUT_FILENO);
		g_box->env_list = g_box->env_list->next;
	}
	return (EXIT_SUCCESS);
}
