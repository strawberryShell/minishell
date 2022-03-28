/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:34:04 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 15:34:18 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_children(t_box *box)
{
	int		status;
	int		last_status;
	pid_t	child_pid;
	pid_t	last_pid;

	last_pid = ((t_cmd*)(ft_lstlast(box->cmd_lst)->content))->pid;
	child_pid = 0;
	while (child_pid != -1)
	{
		child_pid = waitpid(-1, &status, 0);
		if (child_pid == last_pid)
			last_status = status;
	}
	if (WIFEXITED(last_status))
		box->status = WEXITSTATUS(last_status);
	else if (WIFSIGNALED(last_status))
		box->status = WTERMSIG(last_status);
	else
		box->status = EXIT_FAILURE;
}
