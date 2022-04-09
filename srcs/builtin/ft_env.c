/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:24 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 21:05:05 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **argv)
{
	t_list	*ptr;

	ptr = g_box->env_list;
	if (argv[1])
	{
		if (is_option(argv[1], "env"))
			return (EXIT_FAILURE);
		print_err("env", argv[1], strerror(ENOENT));
		return (127);
	}
	while (ptr)
	{
		if (ft_strchr(ptr->content, '='))
			ft_putendl_fd((char *)ptr->content, STDOUT_FILENO);
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}
