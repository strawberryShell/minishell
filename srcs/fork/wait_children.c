/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:34:04 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/08 14:59:44 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_children(void)
{
	int		status;
	int		last_status;
	pid_t	child_pid;
	pid_t	last_pid;

	last_pid = ((t_cmd *)(ft_lstlast(g_box->cmd_list)->content))->pid;
	child_pid = 0;
	while (child_pid != -1)
	{
		child_pid = waitpid(-1, &status, 0);
		if (child_pid == last_pid)
			last_status = status;
	}
	if (WIFEXITED(last_status))
		g_box->exit_code = WEXITSTATUS(last_status);
	else if (WIFSIGNALED(last_status))
	{
		g_box->exit_code = 128 + WTERMSIG(last_status);
		if (g_box->exit_code == 131)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
	}	
	else
		g_box->exit_code = EXIT_FAILURE;
}
