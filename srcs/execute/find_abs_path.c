/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_abs_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:22:17 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 15:30:36 by sehhong          ###   ########.fr       */
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

static	char	*find_in_env(t_list *env_list, char *name)
{
	char	**paths;
	char	*abs_path;
	int		fd;

	paths = ft_split(get_env(env_list, "PATH"), ':');
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

char	*find_abs_path(t_list *env_list, char *name)
{
	int		fd;
	char	*abs_path;

	fd = open(name, O_RDONLY);
	if (fd >= 0)
	{
		abs_path = name;
		close(fd);
	}
	else
		abs_path = find_in_env(env_list, name);
	return (abs_path);
}
