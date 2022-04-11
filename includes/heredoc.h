/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:00:35 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 18:24:06 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

char	*create_tmpfile(int *tmp_fd);
void	delete_tmpfile(t_ast *rdr);
char	*launch_heredoc(char *lim);

#endif
