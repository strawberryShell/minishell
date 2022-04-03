/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:36:55 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/04 03:08:36 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_realloc(int len, char *prev, char word)
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

/**
 * @brief str($로 시작하는 parameter의 syntax check.)
 * 알파벳과 숫자, 소수의 special parameter가 아닌 경우 0을 리턴한다.
 * $로만 끝나는 경우도 0을 리턴한다.
 */
static int	check_param(char *str)
{
	str++;
	return (*str && (ft_isalnum(*str) || ft_strchr("!#$*-?@_", *str)));
}

char	*substitute_env(t_list *env_list, char **start, char *str)
{
	char	*end;
	char	*env;
	char	*value;

/**
 * @brief 숫자거나 special varable이면 한글자까지만 끊는다.
 */
	end = ++(*start);
	if (ft_isdigit(*end) || ft_strchr("!#$*-?@_", *end))
		end++;
	else
	{
		/**
		 * @brief 알파벳, 숫자, _가 아닌 문자를 만나면 끊는다. 언더바 정말 .똘아이네요
		 */
		while (*end && (ft_isalnum(*end) || *end == '_'))
			end++;
	}
	env = ft_substr(*start, 0, end - *start);
	*start = --end;
	value = get_env(env_list, env);
	free(env);
	if (!value)
		value = "";
	if (!str)
		str = "";
	return (ft_strjoin(str, value));
}

char	*remove_quote(t_list *env_list, t_ttype type, char *word)
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
			if (type != SYMBOL_HERE && *word == '$' && quote != '\'' && check_param(word))
				result = substitute_env(env_list, &word, result);
			else
				result = ft_realloc(len++, result, *word);
		}
		word++;
	}
	return (result);
}

int	check_pipe(t_token *token, t_ast *ptr)
{
	if (!(token->next) || token->next->type == PIPE
		|| !(ptr->left || ptr->right))
		return (-1);
	ptr->right = subtree_pipeseq();
	return (0);
}

int	check_rdr(t_list *env_list, t_token *token, t_ast *ptr)
{
	char	*word;

	if (!(token->next) || token->next->type != WORD)
		return (-1);
	word = remove_quote(env_list, token->type, token->next->data);
	if (token->type == SYMBOL_HERE)
		printf("heredoc 처리하고 word를 filename으로 치환");
	if (ptr->left)
	{
		ptr = ptr->left;
		while (ptr->right != NULL)
			ptr = ptr->right;
		ptr->right = subtree_rdr(token->data, word);
	}
	else
		ptr->left = subtree_rdr(token->data, word);
	return (0);
}

int	check_word(t_list *env_list, t_token *token, t_ast *ptr)
{
	char	*word;

	word = remove_quote(env_list, token->type, token->data);
	while (ptr->right != NULL)
		ptr = ptr->right;
	if (ptr->type == CMD)
	{
		ptr->data = word; //builtin 구분을 위한 data 설정
		ptr->right = subtree_simple_command(SIMPLE_CMD, word);
	}
	else
		ptr->right = subtree_simple_command(ARGV, word);
	return(0);
}

int	check_syntax(t_list *env_list, t_token **head, t_ast **ptr)
{
	int		result;

	if ((*head)->type == PIPE)
	{
		result = check_pipe(*head, *ptr);
		*ptr = (*ptr)->right; //next pipe
	}
	else if ((*head)->type == SYMBOL || (*head)->type == SYMBOL_HERE)
	{
		result = check_rdr(env_list, *head, (*ptr)->left); // PIPESEQ -> CMD
		if (!result)
			*head = (*head)->next;
	}
	else
		result = check_word(env_list, *head, (*ptr)->left); // PIPESEQ -> CMD
	return (result);
}
