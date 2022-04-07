/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:07:18 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 00:37:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

int		execute_builtin(char **argv, t_ctype cmd_type);
void	execute_command(t_ast *scmd);
char	*find_abs_path(char *name);
void	make_argv(char ***argv, t_ast *argv_tree);
t_ctype	which_cmd_type(char *name);

#endif