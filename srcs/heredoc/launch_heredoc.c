/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:08:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 20:30:04 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static	int	is_signaled(char **tmp_fname)
{
	if (!g_box->h_flag)
	{
		unlink(*tmp_fname);
		free(*tmp_fname);
		*tmp_fname = NULL;
		return (1);
	}
	return (0);
}

char	*launch_heredoc(char *lim)
{
	char	*tmp_fname;
	int		tmp_fd;
	char	*line_read;

	tmp_fd = -1;
	line_read = NULL;
	tmp_fname = create_tmpfile(&tmp_fd);
	g_box->h_flag = 1;
	while (1)
	{
		free_ptr((void **)&line_read);
		line_read = readline("> ");
		if (!line_read)
			break ;
		if (is_signaled(&tmp_fname))
			break ;
		line_read = get_replaced_readline(line_read);
		if (!ft_strncmp(line_read, lim, ft_strlen(lim) + 1))
			break ;
		write_on_tmp_file(line_read, tmp_fd);
	}
	free_ptr((void **)&line_read);
	close(tmp_fd);
	g_box->h_flag = 0;
	return (tmp_fname);
}
