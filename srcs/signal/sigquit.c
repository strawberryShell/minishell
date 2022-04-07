/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:54:54 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/08 03:28:52 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigquit_handler(int signum)
{
	pid_t	pid;
	t_list	*ptr;

	if (signum != SIGQUIT)
		return ;
	ptr = g_box->cmd_list;
	while (ptr)
	{
		pid = ((t_cmd *)(ptr->content))->pid;
		kill(pid, SIGQUIT);
		ptr = ptr->next;
	}
	if (g_box->exit_code == 131)
		ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
}