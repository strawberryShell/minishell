/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:21:57 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 18:22:04 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd)
{
	if (prev_cmd)
	{
		ft_close(prev_cmd->fds[WR_FD]);
		ft_dup2(prev_cmd->fds[RD_FD], STDIN_FILENO);
		ft_close(prev_cmd->fds[RD_FD]);
	}
	if (curr_cmd->fds[RD_FD] != -1)
	{
		ft_close(curr_cmd->fds[RD_FD]);
		ft_dup2(curr_cmd->fds[WR_FD], STDOUT_FILENO);
		ft_close(curr_cmd->fds[WR_FD]);
	}
}
