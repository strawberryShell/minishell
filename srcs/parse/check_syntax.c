/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:55 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/28 18:13:21 by jiskim           ###   ########.fr       */
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
			if (type != SYMBOL_HERE && *word == '$' && quote != '\'')
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

int	check_pipe(t_token *token, t_ast *ptr)
{
	if (!(token->next) || token->next->type == PIPE \
	|| !(ptr->left || ptr->right))
		return (-1);
	ptr->right = subtree_pipeseq();
	return (0);
}

int	check_rdr(t_token *token, t_ast *ptr)
{
	char	*word;

	if (!(token->next) || token->next->type != WORD)
		return (-1);
	// $ 처리 (<< 제외 모두) 및 "", '' 처리
	while (ptr != NULL)
		ptr = ptr->right;
	word = remove_quote(token->type, token->next->data);
	if (token->type == SYMBOL_HERE)
		printf("heredoc 처리하고 word를 filename으로 치환");
	ptr = subtree_rdr(token->data, word);
	return (0);
}

int	check_word(t_token *token, t_ast *ptr)
{
	char	*word;

	// $ 처리 및 "" '' 처리
	while (ptr->right != NULL)
		ptr = ptr->right;
	word = remove_quote(token->type, token->data);
	if (ptr->type == CMD)
	{
		ptr->data = word; //builtin 구분을 위한 data 설정
		ptr->right = subtree_simple_command(SIMPLE_CMD, word);
	}
	else
		ptr->right = subtree_simple_command(ARGV, word);
	return(0);
}

int	check_syntax(t_token **head, t_ast **ptr)
{
	int		result;

	if ((*head)->type == PIPE)
	{
		result = check_pipe(*head, *ptr);
		*ptr = (*ptr)->right; //next pipe
	}
	else if ((*head)->type == SYMBOL || (*head)->type == SYMBOL_HERE)
	{
		result = check_rdr(*head, (*ptr)->left->left); // PIPESEQ -> CMD -> (RDR - nullable)
		if (!result)
			*head = (*head)->next;
	}
	else
		result = check_word(*head, (*ptr)->left); // PIPESEQ -> CMD
	return (result);
}
