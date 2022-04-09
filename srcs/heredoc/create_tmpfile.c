/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmpfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:16:20 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 20:29:57 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*create_tmpfile(int *tmp_fd)
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
