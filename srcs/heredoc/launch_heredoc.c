/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:08:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 18:18:27 by jiskim           ###   ########.fr       */
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

static	void	delete_file(char **filename)
{
	unlink(*filename);
	free(*filename);
	*filename = NULL;
}

char	*launch_heredoc(char *lim)
{
	char	*tmp_fname;
	int		tmp_fd;
	char	*line_read;

	tmp_fd = -1;
	g_box->h_flag = 1;
	tmp_fname = create_tmpfile(&tmp_fd);
	line_read = readline("> ");
	while (line_read && g_box->h_flag)
	{
		line_read = get_replaced_readline(line_read);
		if (!ft_strncmp(line_read, lim, ft_strlen(lim) + 1))
			break ;
		write_on_tmp_file(line_read, tmp_fd);
		free_ptr((void **)&line_read);
		line_read = readline("> ");
	}
	free_ptr((void **)&line_read);
	close(tmp_fd);
	if (!g_box->h_flag)
		delete_file(&tmp_fname);
	g_box->h_flag = 0;
	return (tmp_fname);
}
