#include "minishell.h"

void    builtin_cd(t_list *env_lst, char **argv)
{
    int	ret;

	if (argv[1])	// {"cd", "dir", 0} -> cmd: cd dir (dir로 간다)
	{
		ret = chdir(argv[1]);
		if (ret < 0)
		{
			print_err("cd", argv[1], strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	else	// {"cd", 0} -> cmd: cd (home으로 간다)
	{
		ret = chdir(get_env_value(env_lst, "HOME"));
		if (ret < 0)
		{
			print_err("cd", NULL, "HOME not set");
			exit(EXIT_FAILURE);
		}
	}
}
