/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:48:52 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/09 14:41:25 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initiate_box(char **envp)
{
	g_box = (t_box *)ft_calloc(1, sizeof(t_box));
	while (*envp)
	{
		ft_lstadd_back(&(g_box->env_list), ft_lstnew(ft_strdup(*envp)));
		envp++;
	}
}

void	initiate_signal_setting(void)
{
	off_echoctl();
	signal(SIGINT, control_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_eof(char *line_read)
{
	if (!line_read)
	{
		ft_putendl_fd("exit", STDERR_FILENO);
		exit(g_box->exit_code);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line_read;

	initiate_box(envp);
	line_read = NULL;
	if (argc > 1)
		exit_with_err(argv[1], strerror(ENOENT), 127);
	write(2, SH_IMG, 2039);
	while (1)
	{
		initiate_signal_setting();
		if (line_read)
			free_ptr((void **)&line_read);
		line_read = readline("딸기쉘🍓$ ");
		handle_eof(line_read);
		if (line_read && *line_read)
		{
			add_history(line_read);
			parse(line_read);
		}
	}
	free_ptr((void **)&line_read);
	return (0);
}
