/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:06 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 18:54:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_no_arg(t_list *env_list)
{
	char	*equal_ptr;
	char	*ptr;

	while (env_list)
	{
		ptr = (char *)env_list->content;
		equal_ptr = ft_strchr(ptr, '=');
		while (*ptr && *ptr != '=')
		{	
			write(STDOUT_FILENO, ptr, 1);
			ptr++;
		}
		if (equal_ptr)
		{
			ptr++;
			write(STDOUT_FILENO, "=\"", 2);
			write(STDOUT_FILENO, ptr, ft_strlen(ptr));
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		env_list = env_list->next;
	}
}

static	int	get_keylen(char *str)
{
	int	key_len;

	key_len = 0;
	while (*str)
	{
		if (*str == '=')
			break ;
		key_len++;
		str++;
	}
	return (key_len);
}

static	int	cmp_after_key(char *data, char *arg, int key_len)
{
	data += key_len;
	arg += key_len;
	while (*data || *arg)
	{
		if (*data != *arg)
			return (1);
		data++;
		arg++;
	}
	return (0);
}

static	void	export_with_arg(t_list **env_list, char *arg)
{
	t_list	*curr;
	int		key_len;
	char	*data;

	key_len = get_keylen(arg);
	curr = *env_list;
	while (curr)
	{
		data = (char *)curr->content;
		if (!ft_strncmp(data, arg, key_len)
			&& (data[key_len] == '\0' || data[key_len] == '='))
		{
			if (arg[key_len] == '=' && cmp_after_key(data, arg, key_len))
			{
				free(data);
				curr->content = ft_strdup(arg);
			}
			break ;
		}
		curr = curr->next;
	}
	if (!curr)
		ft_lstadd_back(env_list, ft_lstnew(ft_strdup(arg)));
}

// TODO 특수기호 $ 최종확인 필요
int	ft_export(t_list **env_list, char **argv)
{
	argv++;
	if (!*argv)
	{
		export_no_arg(*env_list);
		return (EXIT_SUCCESS);
	}
	if (is_option(*argv, "export"))
		return (2);
	while (*argv)
	{
		if (!is_valid_key(*argv))
		{	
			print_err2("export", *argv, "not a valid identifier");
			return (EXIT_FAILURE);
		}
		else
			export_with_arg(env_list, *argv);
		argv++;
	}
	return (EXIT_SUCCESS);
}
