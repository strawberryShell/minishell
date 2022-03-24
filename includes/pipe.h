/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:23:02 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 17:01:41 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "structure.h"

void	adjust_command(t_box *box, t_ast *tree);
void	connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd);
void    execute_command(t_box *box, char *cmd_name);
void	extend_argv(t_cmd *cmd, char *new_arg);
void	make_argv(t_box *box, char *arg);
void	redirect_files(t_ast *io);
void	run_command(t_box *box, t_ast *tree);
void	save_path(t_box *box, t_ast *tree);

#endif