/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:29:33 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 15:29:50 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  int     count_arg(char **argv)
{
    int num_arg;

    num_arg = 0;
    while (*argv++)
        num_arg++;
    return (num_arg + 1);

}

void    extend_argv(t_cmd *curr_cmd, char *new_arg)
{
    char    **argv;
    char    **new_argv;
    int     i;

    argv = curr_cmd->argv;
    new_argv = (char **)ft_calloc(count_arg(argv) + 1, sizeof(char *));
    i = -1;
    while (argv[++i])
        new_argv[i] = argv[i];
    new_argv[i] = new_arg;
    free_ptr(argv);
    argv = new_argv;
}