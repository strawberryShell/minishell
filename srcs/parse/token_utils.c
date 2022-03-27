/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:00:14 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/28 02:33:20 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief
 *
 * @param data nullable
 * @return t_token*
 *
 * << >> < > | 그 외
 */
t_token	*new_token(char *data)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (ft_strchr("<>|", *data))
	{
		if (*data == '|')
			new->type = PIPE;
		else if (data[0] == '<' && data[1] == '<')
			new->type = SYMBOL_HERE;
		else
			new->type = SYMBOL;
		new->data = data;
	}
	else
	{
		new->type = WORD;
		new->data = data;
	}
	return (new);
}

/**
 * data는 ast에서 그대로 사용되므로 free하지 않습니다.
 */
void	free_token_list(t_token *list)
{
	t_token *tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list->data);
		free(list);
		list = tmp;
	}
}

void	add_token(t_token **list, t_token *new)
{
	t_token	*tmp;

	tmp = *list;
	if (!*list)
	{
		*list = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_ast	*syntax_analysis(t_token *list)
{
	t_ast	*root;
	t_ast	*ptr;

	root = subtree_pipeseq();
	ptr = root->left;
	while (list)
	{
		printf("(%d %s)->", list->type, list->data);
		if (check_syntax(&list, &ptr) < 0)
		{
			ft_putstr_fd("딸기쉘: syntax error near unexpected token `", 2);
			if (list->type == PIPE)
				ft_putstr_fd(list->data, 2);
			else if (list->next)
				ft_putstr_fd(list->next->data, 2);
			else
				ft_putstr_fd("newline", 2);
			ft_putendl_fd("'", 2);
			free_ast(root);
			return (NULL);
		}
		list = list->next;
	}
	printf("\n");
	preorder_ast(root, 1);
	return (root);
}
