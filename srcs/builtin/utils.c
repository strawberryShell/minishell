/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:23:26 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/03 01:00:59 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 환경변수(key)에 상응하는 value를 반환하는 함수 
char	*get_env(t_list *env_list, char *key)
{
	while(env_list)
	{
		if (is_same_key(env_list->content, key))
			return (ft_strchr(env_list->content, '=') + 1);
		env_list = env_list->next;
	}
	return (NULL);
}

int	is_same_key(char *str, char *key)
{
	int	key_len;

	key_len = ft_strlen(key);
	if (!ft_strncmp(str, key, key_len) && str[key_len] == '=')
		return (1);
	return (0);
}


static	void	print_usage(char *cmd)
{
	if (!ft_strncmp(cmd, "cd", 3))
		ft_putendl_fd("cd [directory]", STDERR_FILENO);
	else if (!ft_strncmp(cmd, "pwd", 4))
		ft_putendl_fd("pwd [argument]", STDERR_FILENO);
	else if (!ft_strncmp(cmd, "env", 4))
		ft_putendl_fd("env", STDERR_FILENO);
	else if (!ft_strncmp(cmd, "export", 7))
		ft_putendl_fd("export [name[=value] ...]", STDERR_FILENO);
	else if (!ft_strncmp(cmd, "unset", 6))
		ft_putendl_fd("unset [name ...]", STDERR_FILENO);
}

int	is_option(char *str, char *cmd)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		if (str[i + 1])
		{
			ft_putstr_fd("딸기쉘: ", STDERR_FILENO);
			ft_putstr_fd(cmd, STDERR_FILENO);
			ft_putstr_fd(": ", STDERR_FILENO);
			write(STDERR_FILENO, str, 2);
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putendl_fd("option not allowed", STDERR_FILENO);
			ft_putstr_fd(cmd, STDERR_FILENO);
			ft_putstr_fd(": usage: ", STDERR_FILENO);
			print_usage(cmd);
			return (1);
		}
	}
	return (0);
}