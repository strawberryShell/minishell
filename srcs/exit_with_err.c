/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:30:20 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/17 17:04:25 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void   exit_with_err(char *str1, char *str2, int exit_code)
{
    ft_putstr_fd("딸기쉘🍓: ", STDIN_FILENO);
    ft_putstr_fd(str1, STDIN_FILENO);
    if (str2)
    {
        ft_putstr_fd(": ", STDIN_FILENO);
        ft_putstr_fd(str2, STDIN_FILENO);
    }
    ft_putstr_fd("\n", STDIN_FILENO);
    exit(exit_code);
}
