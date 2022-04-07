/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:08:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 17:50:43 by sehhong          ###   ########.fr       */
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
	tmp_name = ft_strjoin(tmp_dir, "tmp_");
	full_name = ft_strjoin(tmp_name, num_str);
	free_ptr((void **)&tmp_name);
	free_ptr((void **)&num_str);
	return (full_name);
}

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

static char	*ft_realloc(char *prev, char word)
{
	char	*new;
	int		len;
	int		i;

	if (!prev)
		len = 0;
	else
		len = ft_strlen(prev);
	new = ft_calloc(len + 2, 1);
	i = 0;
	if (prev)
	{
		while (prev[i])
		{
			new[i] = prev[i];
			i++;
		}
		free(prev);
	}
	new[i] = word;
	return (new);
}

static	char	*get_replaced_readline(char *line_read)
{
	char	*new_str;
	char	*ptr;

	if (!*line_read)
		return (line_read);
	ptr = line_read;
	new_str = NULL;
	while (*ptr)
	{
		if (*ptr == '$')
			new_str = substitute_env(&ptr, new_str);
		else
			new_str = ft_realloc(new_str, *ptr);
		ptr++;
	}
	free_ptr((void **)&line_read);
	return (new_str);
}

static	void	write_on_tmp_file(char *str, int tmp_fd)
{
	char	*tmp_str;

	tmp_str = ft_strjoin(str, "\n");
	ft_putstr_fd(tmp_str, tmp_fd);
	free(tmp_str);
	tmp_str = NULL;
}

char	*launch_heredoc(char *lim)
{
	char	*tmp_fname;
	int		tmp_fd;
	char	*line_read;

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
			line_read = get_replaced_readline(line_read);
			if (!ft_strncmp(line_read, lim, ft_strlen(lim) + 1))
				break ;
			write_on_tmp_file(line_read, tmp_fd);
		}
	}
	free_ptr((void **)&line_read);
	close(tmp_fd);
	return (tmp_fname);
}
