/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:21:57 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/19 23:34:53 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd)
{
    if (prev_cmd) //nth, last
    {
        ft_close(prev_cmd->fds[WR_FD]);
        ft_dup2(prev_cmd->fds[RD_FD], STDIN_FILENO);
        ft_close(prev_cmd->fds[RD_FD]);
    }   
    // 이게 맞는 조건문인가?
    if (curr_cmd->fds[RD_FD]) //1st, nth
    {
        ft_close(curr_cmd->fds[RD_FD]);
        ft_dup2(curr_cmd->fds[WR_FD], STDOUT_FILENO);
        ft_close(curr_cmd->fds[WR_FD]);
    }
        
}