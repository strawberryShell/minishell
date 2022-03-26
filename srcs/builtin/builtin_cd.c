/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:20 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/26 23:57:11 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    builtin_cd(t_list *env_lst, char **argv)
{
    int		ret;
	char	*home_value;

	if (argv[1])	// {"cd", "dir", 0} -> cmd: cd dir (dir로 간다)
	{
		if (is_special_var(argv[1]))
		{
			print_err("cd", argv[1], "invalid syntax");
			return (EXIT_FAILURE);
		}
		ret = chdir(argv[1]);
		if (ret < 0)
		{
			print_err("cd", argv[1], strerror(errno));
			return (EXIT_FAILURE);
		}
	}
	else	// {"cd", 0} -> cmd: cd (home으로 간다)
	{
		home_value = get_env_value(env_lst, "HOME");
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
