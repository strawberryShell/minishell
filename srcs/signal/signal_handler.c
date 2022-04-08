/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:04:17 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/08 22:21:46 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// readline 하는 중
void	sigint_handler_p(int signum)
{
	if (signum != SIGINT)
		return ;
	g_box->exit_code = EXIT_FAILURE;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

// 자식들이 일하는 중
void	sigint_handler_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(STDOUT_FILENO, "\n", 1);
	return ;
}

void	sigquit_handler(int signum)
{
	if (signum != SIGQUIT)
		return ;
}
