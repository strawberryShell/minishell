/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:09 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/06 19:16:49 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief when nflag return zero.
 *
 * @param str
 * @return int
 */
static	int	is_nflag(char *str)
{
	if (*str++ == '-')
	{
		if (!*str)
			return (0);
		while (*str == 'n')
			str++;
		if (!*str)
			return (1);
	}
	return (0);
}

// The return status is 0 unless a write error occurs.
int	ft_echo(char **argv)
{
	int	nflag;
	int	i;

	argv++;
	nflag = 0;
	if (*argv)
	{
		nflag = is_nflag(*argv);
		if (nflag)
			argv++;
	}
	i = 0;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], STDOUT_FILENO);
		if (argv[i + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
	if (!nflag)
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
