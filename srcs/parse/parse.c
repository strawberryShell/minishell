/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/28 16:56:35 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	parse(char *line)
{
	char	*start;
	char	*end;
	char	quote;
	t_token	*token_list;
	t_ast	*root;

	start = line;
	end = start;
	quote = 0;
	token_list = NULL;
	while (*start)
	{
		while (*start && ft_strchr("\t\n\v\f\r ", *start))
			start++;
		end = start;
		while (*end && !ft_strchr("\t\n\v\f\r ", *end))
		{
			if (quote == 0 && ft_strchr("'\"", *end))
				quote = *end;
			end++;
			if (quote)
			{
				while (*end && *end != quote)
					end++;
				if (*end == quote)
				{
					end++;
					quote = 0;
				}
			}
			if (ft_strchr("<>|", *start))
			{
				if (*start == *end && *start != '|')
					end++;
				break;
			}
			if (ft_strchr("<>|", *end))
				break;
		}
		if (start < end)
			add_token(&token_list, new_token(ft_substr(start, 0, (end - start))));
		start = end;
	}
	if (quote)
		ft_putendl_fd("Syntax error", 2);
	root = syntax_analysis(token_list);
	free_token_list(token_list);
	free_ast(root);
}
