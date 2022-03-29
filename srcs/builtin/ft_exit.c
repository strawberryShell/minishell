/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:01 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/29 17:16:03 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static  int     is_number(char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int    ft_exit(char **argv, int *not_exit)
{
    int exit_code;
    
    exit_code = 0;
    argv++;
    if (!*argv)
        return (EXIT_SUCCESS);
    if (!is_number(*argv))
    {
        print_err("exit", *argv, "numeric argument required");
        return (255);
    }
	exit_code = ft_atoi(*argv) % 256;
    argv++;
    if (*argv)
    {
        print_err("exit", NULL, "too many arguments");
        if (not_exit)
            *not_exit = 1;
        return (EXIT_FAILURE);
    }
    return (exit_code);
}

/* 첫 인자가 숫자가 아닐때(exit abc 1 2 3 4)
exit
bash: exit: abc: numeric argument required

exit_code =  255 (나감)
*/

/* 첫인자가 숫자일때 (exit 1 a b c) (exit 1 2 3 4)
exit
bash: exit: too many arguments

exit_code = 1 (안나감)
*/

/*첫 인자가 숫자이고 인자가 하나일때  (exit 515)
exit

exit_code = 3 (ㄴㅏ감)
*/

/*아무 인자없을 때 (exit)
exit

exit_code = 0 (나감)
*/

