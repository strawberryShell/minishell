/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:01:23 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 03:17:55 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	exit_with_err(char *str1, char *str2, int exit_code);
void	free_ptr(void **ptr);
int		ft_open(char *fname, int oflag, int mode);
void	ft_close(int fd);
void	ft_dup2(int fd1, int fd2);
void    ft_pipe(int *fds);
pid_t	ft_fork(void);
char	*substitute_env(t_list *env_list, char **start, char *str);

#endif
