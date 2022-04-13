/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_abs_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:22:17 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/13 18:02:11 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*make_full_path(char *path, char *name)
{
	char	*tmp_path;
	char	*abs_path;

	tmp_path = ft_strjoin(path, "/");
	abs_path = ft_strjoin(tmp_path, name);
	free_ptr((void **)&tmp_path);
	return (abs_path);
}

static	char	*find_in_env(char *name)
{
	char	**paths;
	char	*abs_path;
	int		fd;

	paths = ft_split(get_env("PATH"), ':');
	if (!paths)
		return (name);
	while (*paths)
	{
		abs_path = make_full_path(*paths, name);
		fd = open(abs_path, O_RDONLY);
		if (fd < 0)
			free_ptr((void **)&abs_path);
		else
		{
			close(fd);
			break ;
		}
		paths++;
	}
	if (abs_path)
		return (abs_path);
	return (name);
}

char	*find_abs_path(char *name)
{
	if (ft_strchr(name, '/'))
		return (name);
	return (find_in_env(name));
}
