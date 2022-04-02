/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:20 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/02 19:06:31 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_list *env_list, char **argv)
{
    int		ret;
	char	*home_value;

	if (argv[1])	// {"cd", "dir", 0} -> cmd: cd dir (dir로 간다)
	{
		if (is_option(argv[1], "cd"))
			return (EXIT_FAILURE);
		ret = chdir(argv[1]);
		if (ret < 0)
		{
			print_err("cd", argv[1], strerror(errno));
			return (EXIT_FAILURE);
		}
	}
	else	// {"cd", 0} -> cmd: cd (home으로 간다)
	{
		home_value = get_env(env_list, "HOME");
		if (!home_value)
		{
			print_err("cd", NULL, "HOME not set");
			return (EXIT_FAILURE);		
		}
		ret = chdir(home_value);
		if (ret < 0)
		{
			print_err("cd", NULL, strerror(errno));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
