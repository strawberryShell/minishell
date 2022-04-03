/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:50:49 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/02 19:26:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **argv)
{
    char    *cwd;

    if (argv[1] && is_option(argv[1], "pwd"))
        return (EXIT_FAILURE);
    cwd = getcwd(NULL, 0);
    if (!cwd)
    {
        print_err("pwd", NULL, strerror(errno));
        return (EXIT_FAILURE);
    }
    ft_putendl_fd(cwd, STDOUT_FILENO);
    free(cwd);
    cwd = NULL;
	return (EXIT_SUCCESS);
}
