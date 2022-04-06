/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/07 03:27:04 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	*syntax_analysis(t_list *env_list, t_token *list)
{
	t_ast	*root;
	t_ast	*ptr;

	root = subtree_pipeseq();
	ptr = root;
	while (list)
	{
		if (check_syntax(env_list, &list, &ptr) < 0)
		{
			ft_putstr_fd("딸기쉘: syntax error near unexpected token `",
				STDERR_FILENO);
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
	// TODO 완성 시 삭제
	preorder_ast(root, 1, 1);
	return (root);
}

int	skip_quote(char **end, t_token *token_list)
{
	char	quote;
	char	*str;

	quote = **end;
	str = *end + 1;
	while (*str && *str != quote)
		str++;
	*end = str;
	if (*str == quote)
		return (0);
	free_token_list(token_list);
	ft_putstr_fd("딸기쉘: unexpected EOF while looking for matching `",
		STDERR_FILENO);
	ft_putchar_fd(quote, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	return (-1);
}

t_token	*tokenization(char *line)
{
	char	*end;
	t_token	*token_list;

	token_list = NULL;
	while (*line)
	{
		while (*line && ft_strchr("\t\n\v\f\r ", *line))
			line++;
		end = line;
		while (*end && !ft_strchr("<>|\t\n\v\f\r ", *end))
		{
			if (ft_strchr("'\"", *end))
				if (skip_quote(&end, token_list))
					return (NULL);
			end++;
		}
		if (*end && ft_strchr("<>|", *line))
			if (*line == *++end && *line != '|')
				end++;
		if (line < end)
			add_token(&token_list, new_token(ft_substr(line, 0, (end - line))));
		line = end;
	}
	return (token_list);
}

void	parse(t_box *box, char *line)
{
	t_token	*token_list;
	t_ast	*root;

	token_list = tokenization(line);
	if (token_list)
	{
		root = syntax_analysis(box->env_list, token_list);
		if (root)
			read_ast(box, root);
		free_token_list(token_list);
		free_ast(root);
	}
}
