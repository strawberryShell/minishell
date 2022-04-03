/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:33 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/01 16:23:54 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

void	fork_child(t_box *box, t_ast *tree, t_cmd *prev_cmd);
int		need_fork(t_cmd *prev_cmd, t_ast *tree);
void	run_without_fork(t_box *box, t_ast *cmd, t_ctype cmd_type);
void	wait_children(t_box *box);

#endif
