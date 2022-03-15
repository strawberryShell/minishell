/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:20:06 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/15 17:00:35 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_no_arg(t_list *env_lst)
{
	char	*equal_ptr;
	char	*ptr;

	while(env_lst)
	{
		ptr = (char*)env_lst->content;
		equal_ptr = ft_strchr(ptr, '=');
		printf("declare -x ");
		while (*ptr != '=' && *ptr)
		{	
			write(STDOUT_FILENO, ptr, 1);
			ptr++;
		}
		if (equal_ptr)
			printf("=\"%s\"", ++ptr);
		printf("\n");
		env_lst = env_lst->next;
	}
}

static  int	get_keylen(char *str)
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

static	void	export_with_arg(t_list **env_lst, char *arg)
{
	t_list	*curr;
	int		key_len;
	char	*data;

	key_len = get_keylen(arg);
	curr = *env_lst;
	while (curr)
	{
		data =(char *)curr->content;
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
	}
	if (!curr)
		ft_lstadd_back(env_lst, ft_lstnew(ft_strdup(arg)));
}

void	builtin_export(t_list **env_lst, char **argv)
{
	argv++;
	if (!*argv)
	{
		export_no_arg(*env_lst);
		return ;
	}
	while (*argv)
	{
		if (**argv == '=')
		{
			ft_putstr_fd("딸기쉘🍓: ", STDERR_FILENO);
			print_blt_err("export", *argv, "not a valid identifier\n");
		}
		else
			export_with_arg(env_lst, *argv);
		argv++;
	}
}
