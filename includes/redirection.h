/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:09:09 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 16:10:49 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

void	connect_pipes(t_cmd *prev_cmd, t_cmd *curr_cmd);
void	redirect_files(t_ast *rdr);

#endif