/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:22:17 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/20 00:01:28 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_path(t_box *box, char *name)
{
	char	**paths;
	char	*tmp_path;
	char	*final_path;
	int		fd;

	final_path = NULL;
	paths = ft_split(get_env_value(box->env_lst, "PATH"), ':');
	if (!paths)
		return (final_path);
	while (*paths)
	{
		tmp_path = ft_strjoin(*paths, "/");
		final_path = ft_strjoin(tmp_path, name);
		free_ptr(tmp_path);
		fd = open(final_path, O_RDONLY);
		if (fd < 0)
			free_ptr(final_path);
		else
		{
			close(fd);
			break ;
		}
		paths++;
	}
	return (final_path);
}

void    extend_argv(t_cmd **cmd, char *new_arg)
{
    int     num_arg;
    char    **argv;
    char    **new_argv;
    int     i;

    num_arg = 0;
    argv = (*cmd)->argv;
    while (argv[i++])
        num_arg++;
    new_argv = (char **)ft_calloc(num_arg + 2, sizeof(char *));
    i = 0;
    while (argv[i])
    {
        new_argv[i] = argv[i];
        i++;
    }
    new_argv[i] = new_arg;
    free(argv);
    argv = NULL;
    (*cmd)->argv = new_argv;
}

void	save_path(t_box **box, t_ast *tree)
{
	int		fd;
    t_cmd  *curr_cmd;

    curr_cmd = ft_lstlast((*box)->cmd_lst);
	// curr_cmd->argv[0] = tree->data;
    // extend_argv(&curr_cmd, (char*)tree->data)
	fd = open(tree->data, O_RDONLY);
	if (fd >= 0)
	{
		(*box)->final_path = ft_strdup(tree->data);
		close(fd);
	}
	else
		(*box)->final_path = search_path(*box, tree->data);
}