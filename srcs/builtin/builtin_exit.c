#include "minishell.h"

int     is_number(char *str)
{
    int ret;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

void    builtin_exit(char **argv)
{
    int exit_code;
    
    exit_code = 0;
    argv++;
    if (!*argv)
    {
        ft_putendl_fd("exit", STDOUT_FILENO);
        exit(EXIT_SUCCESS);
    }
    if (!is_number(*argv))
    {
        ft_putendl_fd("exit");
        print_blt_err("exit", *argv, "numeric argument required");
        exit(255);
    }
	exit_code = ft_atoi(*argv) % 256;
    argv++;
    if (*argv)
    {
        ft_putendl_fd("exit");
        print_blt_err("exit", NULL, "too many arguments");
        // $? = EXIT_FAILURE로 바꿔놓기
        return ;
    }
    ft_putendl_fd("exit");
    exit(exit_code);
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

