/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:09:09 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 15:06:24 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

void	connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd);
int		redirect_files_no_fork(t_ast *rdr);
void	redirect_files(t_ast *rdr);

#endif