/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:01 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 00:58:51 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_exit(char **argv, int *if_exit)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	argv++;
	if (!*argv)
		return (g_box->exit_code);
	if (!is_number(*argv))
	{
		print_err("exit", *argv, "numeric argument required");
		return (255);
	}
	exit_code = ft_atoi(*argv) % 256;
	argv++;
	if (*argv)
	{
		print_err("exit", NULL, "too many arguments");
		if (if_exit)
			*if_exit = 0;
		return (EXIT_FAILURE);
	}
	return (exit_code);
}
