/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:30:20 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/25 12:00:51 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void   exit_with_err(char *str1, char *str2, int exit_code)
{
    ft_putstr_fd("딸기쉘🍓: ", STDERR_FILENO);
    ft_putstr_fd(str1, STDERR_FILENO);
    if (str2)
    {
        ft_putstr_fd(": ", STDERR_FILENO);
        ft_putstr_fd(str2, STDERR_FILENO);
    }
    ft_putstr_fd("\n", STDERR_FILENO);
    exit(exit_code);
}
