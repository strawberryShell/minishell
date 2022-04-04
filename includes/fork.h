/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:33 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 13:21:32 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include "structure.h"

void	fork_child(t_box *box, t_ast *tree, t_cmd *prev_cmd);
int		need_fork(t_cmd *prev_cmd, t_ast *tree);
void	run_without_fork(t_box *box, t_ast *cmd, t_ctype cmd_type);
void	wait_children(t_box *box);

#endif