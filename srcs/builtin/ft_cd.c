/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:20 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 00:38:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	print_cd_err(char *str, char *err_msg)
{
	print_err("cd", str, err_msg);
	return (EXIT_FAILURE);
}

int	ft_cd(char **argv)
{
	int		ret;
	char	*home_value;

	if (argv[1])
	{
		if (is_option(argv[1], "cd"))
			return (EXIT_FAILURE);
		ret = chdir(argv[1]);
		if (ret < 0)
			return (print_cd_err(argv[1], strerror(errno)));
	}
	else
	{
		home_value = get_env("HOME");
		if (!home_value)
			return (print_cd_err(NULL, "HOME not set"));
		ret = chdir(home_value);
		if (ret < 0)
			return (print_cd_err(NULL, strerror(errno)));
	}
	return (EXIT_SUCCESS);
}
