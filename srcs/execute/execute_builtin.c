/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:54:37 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 14:01:36 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_box *box, char **argv, t_ctype cmd_type)
{
	int		exit_code;

	if (cmd_type == CD)
		exit_code = ft_cd(box->env_list, argv);
	else if (cmd_type == ECHO)
		exit_code = ft_echo(argv);
	else if (cmd_type == ENV)
		exit_code = ft_env(box->env_list, argv);
	else if (cmd_type == EXIT)
		exit_code = ft_exit(box, argv, NULL);
	else if (cmd_type == EXPORT)
		exit_code = ft_export(&(box->env_list), argv);
	else if (cmd_type == PWD)
		exit_code = ft_pwd(argv);
	else
		exit_code = ft_unset(&(box->env_list), argv);
	return (exit_code);
}
