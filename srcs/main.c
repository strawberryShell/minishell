#include "minishell.h"

int main(int argc, char **argv)
{
	char	*line_read;

	line_read = (char *)NULL;
	if (argc > 1)
    {	
		printf("딸기쉘🍓: %s: %s\n", argv[1], strerror(ENOENT));
		exit (127);
	}
	while (1)
	{
		if (line_read)
		{
			free(line_read);
			line_read = (char *)NULL;
		}
		line_read = readline("딸기쉘🍓$ ");
		if (line_read == NULL)
			printf("null returned.");
		if (line_read && *line_read)
		{
			if (!strcmp(line_read, "exit"))
				break ;
			add_history(line_read);
			printf("%s\n", line_read);
			parse_line(line_read);
		}
	}
	free(line_read);
	line_read = (char *)NULL;
    return (0);
}