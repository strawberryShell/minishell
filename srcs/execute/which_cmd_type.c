/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_cmd_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:57:38 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 22:39:39 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ctype	which_cmd_type(char *name)
{
	t_ctype	ret;

	if (!name)
		ret = NONE;
	else if (!ft_strncmp(name, "cd", 3))
		ret = CD;
	else if (!ft_strncmp(name, "echo", 5))
		ret = EHCO;
	else if (!ft_strncmp(name, "env", 4))
		ret = ENV;
	else if (!ft_strncmp(name, "exit", 5))
		ret = EXIT;
	else if (!ft_strncmp(name, "export", 7))
		ret = EXPORT;
	else if (!ft_strncmp(name, "pwd", 4))
		ret = PWD;
	else if (!ft_strncmp(name, "unset", 6))
		ret = UNSET;
	else
		ret = GENERAL;
	return (ret);
}
