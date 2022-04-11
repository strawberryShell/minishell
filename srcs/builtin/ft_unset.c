/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:21:08 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/10 18:21:01 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	free_node(t_list **ptr)
{
	if (*ptr)
	{
		free((*ptr)->content);
		(*ptr)->content = NULL;
		free(*ptr);
		*ptr = NULL;
	}
}

static	void	delete_node(char *key)
{
	t_list	*curr;
	t_list	*del_node;

	curr = g_box->env_list;
	if (!g_box->env_list)
		return ;
	if (is_same_key(curr->content, key))
	{
		g_box->env_list = curr->next;
		free_node(&curr);
		return ;
	}
	while (curr->next)
	{
		if (is_same_key(curr->next->content, key))
		{
			del_node = curr->next;
			curr->next = del_node->next;
			free_node(&del_node);
			return ;
		}
		curr = curr->next;
	}
}

int	ft_unset(char **argv)
{
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	argv++;
	if (*argv && is_option(*argv, "unset"))
		return (2);
	while (*argv)
	{
		if (!is_valid_key(*argv) || ft_strchr(*argv, '='))
		{
			print_err2("unset", *argv, "not a valid identifier");
			exit_code = EXIT_FAILURE;
		}
		else
			delete_node(*argv);
		argv++;
	}
	return (exit_code);
}
