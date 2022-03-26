#include "minishell.h"

void    builtin_pwd(void)
{
    char    *cwd;

    cwd = getcwd(NULL, 0);
    if (!cwd)
    {
        print_err("pwd", NULL, strerror(errno));
        exit(EXIT_FAILURE);
    }
    ft_putendl_fd(cwd, STDOUT_FILENO);
    free(cwd);
    cwd = NULL;
}