/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:33 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/11 09:46:51 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

void	fork_child(t_ast *tree, t_cmd *prev_cmd);
int		need_fork(t_cmd *prev_cmd, t_ast *tree);
void	run_without_fork(t_ast *cmd, t_ctype cmd_type);
void	wait_children(void);
int		wstatus(int status);
int		wifexited(int status);
int		wexitstatus(int status);
int		wifsignaled(int status);
int		wtermsig(int status);

#endif
