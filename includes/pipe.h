/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:23:02 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/26 14:43:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "structure.h"

void	connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd);
void	run_command(t_box *box, t_ast *scmd);
void	make_argv(char ***argv, t_ast *argv_tree);
void	build_pipes(t_box *box, t_ast *tree);
void	redirect_files(t_box *box, t_ast *rdr);
char	*find_abs_path(t_list *env_lst, char *name);

#endif