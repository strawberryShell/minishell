/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:45:07 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/11 09:45:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wstatus(int status)
{
	return (status & 0177);
}

int	wifexited(int status)
{
	return (wstatus(status) == 0);
}

int	wexitstatus(int status)
{
	return ((status >> 8) & 0x000000ff);
}

int	wifsignaled(int status)
{
	return (wstatus(status) != 0177 && wstatus(status) != 0);
}

int	wtermsig(int status)
{
	return (wstatus(status));
}
