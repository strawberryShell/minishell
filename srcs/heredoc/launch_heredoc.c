/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:08:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 00:48:26 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO 시그널 처리
static	char	*get_tmpfile_name(char *tmp_dir, int i)
{
	char	*tmp_name;
	char	*full_name;
	char	*num_str;

	num_str = ft_itoa(i);
	tmp_name = ft_strjoin(tmp_dir, "tmp-");
	full_name = ft_strjoin(tmp_name, num_str);
	free_ptr((void **)&tmp_name);
	free_ptr((void **)&num_str);
	return (full_name);
}

// TODO line_read에서 $(환경변수) get_env로 바꿔야함.
static	char	*create_tmpfile(int *tmp_fd)
{
	static int	i;
	char		*tmp_dir;
	char		*tmp_fname;

	tmp_dir = get_env("TMPDIR");
	if (!tmp_dir)
		tmp_dir = "/tmp/";
	while (*tmp_fd < 0)
	{
		tmp_fname = get_tmpfile_name(tmp_dir, i);
		*tmp_fd = open(tmp_fname, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC, 0600);
		if (*tmp_fd < 0)
		{
			free_ptr((void **)&tmp_fname);
			i++;
		}
	}
	return (tmp_fname);
}

char	*launch_heredoc(char *lim)
{
	char	*tmp_fname;
	int		tmp_fd;
	char	*line_read;
	char	*tmp_str;

	tmp_fd = -1;
	line_read = NULL;
	tmp_fname = create_tmpfile(&tmp_fd);
	while (1)
	{
		if (line_read)
			free_ptr((void **)&line_read);
		line_read = readline("> ");
		if (line_read)
		{
			if (!ft_strncmp(line_read, lim, ft_strlen(lim) + 1))
				break ;
			tmp_str = ft_strjoin(line_read, "\n");
			ft_putstr_fd(tmp_str, tmp_fd);
			free_ptr((void **)&tmp_str);
		}
	}
	free_ptr((void **)&line_read);
	close(tmp_fd);
	return (tmp_fname);
}
