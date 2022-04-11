/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:04:17 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 19:37:43 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	control_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	g_box->exit_code = EXIT_FAILURE;
	if (g_box->h_flag == 1)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		write(STDOUT_FILENO, "\033[1A", 4);
		g_box->h_flag = 0;
	}
	else
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ignore_signal(int signum)
{
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
}
