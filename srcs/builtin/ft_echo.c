/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:09 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/29 17:36:11 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO 아직 에러 상황을 발견하지 못함.
int	ft_echo(char **argv)
{
    int	nflag;
	int	i;
    
	nflag = 0;
	argv++;
	if (!ft_strncmp(*argv, "-n", 3))
	{
		nflag = 1;
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