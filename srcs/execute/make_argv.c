/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:30:37 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 17:36:52 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	count_arg(char **argv)
{
	int	num_arg;
	int	i;

	i = 0;
	num_arg = 0;
	while (argv[i])
	{
		num_arg++;
		i++;
	}
	return (num_arg + 1);
}

void	make_argv(char ***argv, t_ast *argv_tree)
{
	char	**new_argv;
	int		i;

	if (!argv_tree)
		return ;
	if (argv_tree->type == ARGV)
	{
		new_argv = (char **)ft_calloc(count_arg(*argv) + 1, sizeof(char *));
		i = -1;
		while ((*argv)[++i])
			new_argv[i] = (*argv)[i];
		new_argv[i] = argv_tree->left->data;
		free_ptr((void **)argv);
		*argv = new_argv;
	}
	make_argv(argv, argv_tree->right);
}
