/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:04:57 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 21:48:39 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open(char *fname, int oflag, int mode)
{
	int	fd;

	fd = open(fname, oflag, mode);
	if (fd < 0)
		exit_with_err(fname, strerror(errno), EXIT_FAILURE);
	return (fd);
}

void	ft_close(int fd)
{
	int	ret;

	ret = close(fd);
	if (ret < 0)
		exit_with_err("close()", strerror(errno), EXIT_FAILURE);
}

void	ft_dup2(int fd1, int fd2)
{
	int	ret;

	ret = dup2(fd1, fd2);
	if (ret < 0)
		exit_with_err("dup2()", strerror(errno), EXIT_FAILURE);
}

void	ft_pipe(int *fds)
{
	int	ret;

	ret = pipe(fds);
	if (ret < 0)
		exit_with_err("pipe()", strerror(errno), EXIT_FAILURE);
}

pid_t	ft_fork(void)
{
	int	ret;

	ret = fork();
	if (ret < 0)
		exit_with_err("fork()", strerror(errno), EXIT_FAILURE);
	return (ret);
}
