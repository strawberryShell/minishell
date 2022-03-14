/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:48:52 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/14 16:19:50 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 프로그램 끝날때 env_lst free해주기
// 빌트인: $_ 바꾸기
int main(int argc, char **argv, char **envp)
{
	char	*line_read;
	t_list	*env_lst;

	// env 리스트 초기화
	initiate_env_lst(&env_lst, envp);
	ft_putendl_fd(strerror(errno), 2);
	line_read = (char *)NULL;
	if (argc > 1)
    {
		printf("딸기쉘🍓: %s: %s\n", argv[1], strerror(ENOENT));
		exit(127);
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
			if (!ft_strncmp(line_read, "exit", 5))
				break ;
			add_history(line_read);
			printf("%s\n", line_read);
		}
	}
	free(line_read);
	line_read = (char *)NULL;
    return (0);
}
