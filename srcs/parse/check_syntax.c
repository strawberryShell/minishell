/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:55 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/28 02:36:33 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc(int len, char *prev, char word)
{
	char	*new;
	int		i;

	new = ft_calloc(len + 2, 1);
	i = 0;
	if (prev)
	{
		while (prev[i])
		{
			new[i] = prev[i];
			i++;
		}
		free(prev);
	}
	new[i] = word;
	return (new);
}

char	*remove_quote(t_ttype type, char *word)
{
	char	*result;
	int		len;
	char	quote;

	result = NULL;
	len = 0;
	quote = 0;
	while (*word)
	{
		if (!quote && ft_strchr("'\"", *word))
			quote = *word;
		else if (quote == *word)
			quote = 0;
		else
		{
			if (type != SYMBOL_HERE && *word == '$' && quote != '"')
				printf("blahblah");// 뭔가 $ 처리하는 함수..
			else
				result = ft_realloc(len++, result, *word);
		}
		word++;
	}
	return (result);
}

/**
 * todo: type 별로 syntax check 함수 분리
 */

int	check_syntax(t_token **head, t_ast **ptr)
{
	t_ast	*tmp;
	t_token	*token;
	int		pipe_flag;
	char	*word;

	tmp = *ptr;
	token = *head;
	if (token->type == PIPE)
	{
		if (!(token->next) || token->next->type == PIPE || !(tmp->left || tmp->right))
			return (-1);
		(*ptr)->right = subtree_pipeseq();
		*ptr = (*ptr)->right->left;
		pipe_flag = 1;
	}
	else if (token->type == SYMBOL || token->type == SYMBOL_HERE)
	{
		if (!(token->next) || token->next->type != WORD)
			return (-1);
		// $ 처리 (<< 제외 모두) 및 "", '' 처리
		while (tmp->left != NULL)
			tmp = tmp->left;
		word = remove_quote(token->type, token->next->data);
		if (token->type == SYMBOL_HERE)
			printf("heredoc 처리하고 word를 filename으로 치환");
		tmp->left = subtree_rdr(token->data, word);
		token = token->next;
	}
	else
	{
		// $ 처리 및 "" '' 처리
		while (tmp->right != NULL)
			tmp = tmp->right;
		word = remove_quote(token->type, token->data);
		if (tmp->type == CMD)
			tmp->right = subtree_simple_command(SIMPLE_CMD, word);
		else
			tmp->right = subtree_simple_command(ARGV, word);
	}
	*head = token;
	return (0);
}
