/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:06 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 01:59:51 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_no_arg(void)
{
	char	*equal_ptr;
	char	*key_val;
	t_list	*ptr;

	ptr = g_box->env_list;
	while (ptr)
	{
		key_val = (char *)ptr->content;
		equal_ptr = ft_strchr(key_val, '=');
		while (*key_val && *key_val != '=')
		{	
			write(STDOUT_FILENO, key_val, 1);
			key_val++;
		}
		if (equal_ptr)
		{
			key_val++;
			write(STDOUT_FILENO, "=\"", 2);
			write(STDOUT_FILENO, key_val, ft_strlen(key_val));
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		ptr = ptr->next;
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

static	void	export_with_arg(char *arg)
{
	t_list	*curr;
	int		key_len;
	char	*data;

	key_len = get_keylen(arg);
	curr = g_box->env_list;
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
		ft_lstadd_back(&(g_box->env_list), ft_lstnew(ft_strdup(arg)));
}

// TODO 특수기호 $ 최종확인 필요
int	ft_export(char **argv)
{
	argv++;
	if (!*argv)
	{
		export_no_arg();
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
			export_with_arg(*argv);
		argv++;
	}
	return (EXIT_SUCCESS);
}
