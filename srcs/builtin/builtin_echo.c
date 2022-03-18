#include "minishell.h"

// {"echo", "-n", "h   hh   ", "hoho", "hh   ", 0};
void    builtin_echo(char **argv)
{
    int	nflag;
    
	nflag = 0;
	argv++;
	if (!ft_strncmp(*argv, "-n", 3))
	{
		nflag = 1;
		argv++;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		argv++;
	}
	if (!nflag)
		write(STDOUT_FILENO, "\n", 1);
}