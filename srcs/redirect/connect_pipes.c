/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:21:57 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 13:37:43 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
	자식 프로세스들끼리 단일 방향으로 파이프를 연결하는 과정 
	(이전 프로세스의 stdout -> 현재 프로세스의 stdin)
*/
void	connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd)
{
	/* 
		이전 cmd가 있다! -> n번째 cmd, 마지막 cmd에 해당되는 조건문
		이전 프로세스의 pipe에 wr_fd를 닫고 pipe의 rd_fd를 현재 프로세스의 stdin이 되게끔
		연결한다.
	*/
	if (prev_cmd)
	{
		ft_close(prev_cmd->fds[WR_FD]);
		ft_dup2(prev_cmd->fds[RD_FD], STDIN_FILENO);
		ft_close(prev_cmd->fds[RD_FD]);
	}
	/* 
		fork_child 함수내에서 다음 PIPESEQ가 있으면 ft_pipe()를 통해,
		pipe에 쓰이는 fd값들이 curr_cmd->fds안에 할당됨. 
		(if (tree->right) ft_pipe(curr_cmd->fds);)
		fds안의 값들이 -1이면, fork_child함수에서 pipe를 연결하지 않았다는 뜻.
		fds안의 값들이 -1이 아니면, pipe를 연결했다는 뜻. 즉, 다음 cmd가 존재한다는 뜻.
		이런 경우로는 첫번쨰 cmd이거나 n번째 cmd라는 뜻.
	*/
	if (curr_cmd->fds[RD_FD] != -1)
	{
		ft_close(curr_cmd->fds[RD_FD]);
		ft_dup2(curr_cmd->fds[WR_FD], STDOUT_FILENO);
		ft_close(curr_cmd->fds[WR_FD]);
	}
}
