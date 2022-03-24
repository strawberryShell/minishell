/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:22:17 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 15:29:34 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  char	*search_path(t_box *box, char *name)
{
	char	**paths;
	char	*tmp_path;
	char	*abs_path;
	int		fd;

	abs_path = NULL;
	paths = ft_split(get_env_value(box->env_lst, "PATH"), ':');
	if (!paths)
		return (ft_strdup(name));
	while (*paths)
	{
		tmp_path = ft_strjoin(*paths, "/");
		abs_path = ft_strjoin(tmp_path, name);
		free_ptr(tmp_path);
		fd = open(abs_path, O_RDONLY);
		if (fd < 0)
			free_ptr(abs_path);
		else
		{
			close(fd);
			break ;
		}
		paths++;
	}
	return (abs_path);
}

void	save_path(t_box *box, t_ast *tree)
{
	int		fd;
    char	*abs_path;
	t_cmd	*curr_cmd;

    if (!tree->data)
        return ;
	curr_cmd = (t_cmd*)(ft_lstlast(box->cmd_lst)->content);
	// argv에 첫인자로 추가 (data 원본 그대로)
		extend_argv(curr_cmd, tree->data);
	// 절대 경로로 수정된 path를 abs_path에 추가 
	fd = open(tree->data, O_RDONLY);
	if (fd >= 0)
	{
		curr_cmd->abs_path = ft_strdup(tree->data);
		close(fd);
	}
	else
		curr_cmd->abs_path = search_path(box, tree->data);
}