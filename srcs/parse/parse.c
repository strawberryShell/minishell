/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:13:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/09 21:11:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_syntax_err(t_token *list)
{
	ft_putstr_fd("딸기쉘: syntax error near unexpected token `", 2);
	if (list->type == PIPE)
		ft_putstr_fd(list->data, 2);
	else if (list->next)
		ft_putstr_fd(list->next->data, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putendl_fd("'", 2);
}

t_ast	*syntax_analysis(t_token *list)
{
	t_ast	*root;
	t_ast	*ptr;
	int		result;

	root = subtree_pipeseq();
	ptr = root;
	while (list)
	{
		result = check_syntax(&list, &ptr);
		if (result < 0)
		{
			if (result == -1)
				print_syntax_err(list);
			free_ast(root);
			g_box->exit_code = SYNTAX_ERR;
			return (NULL);
		}
		list = list->next;
	}
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
	ft_putendl_fd("딸기쉘: syntax error: unexpected end of file", STDERR_FILENO);
	g_box->exit_code = SYNTAX_ERR;
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

void	parse(char *line)
{
	t_token	*token_list;
	t_ast	*root;

	token_list = tokenization(line);
	if (token_list)
	{
		root = syntax_analysis(token_list);
		if (root)
			read_ast(root);
		free_token_list(token_list);
		free_ast(root);
	}
}
