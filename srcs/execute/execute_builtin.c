/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:54:37 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 16:20:35 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_list *env_lst, char **argv, t_ctype cmd_type)
{
	int		exit_code;

	if (cmd_type == CD)
		exit_code = builtin_cd(env_lst, argv);
	else if (cmd_type == ECHO)
		exit_code = builtin_echo(argv);
	else if (cmd_type == ENV)
		exit_code = builtin_env(env_lst);
	else if (cmd_type == EXIT)
		exit_code = builtin_exit(argv);
	else if (cmd_type == EXPORT)
		exit_code = builtin_export(&env_lst, argv);
	else if (cmd_type == PWD)
		exit_code = builtin_pwd();
	else
		exit_code = builtin_unset(&env_lst, argv);
	return (exit_code);
}