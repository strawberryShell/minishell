/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:31:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/28 15:59:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft.h"

/**
 * 											PIPESEQ
 * 								CMD							PIPESEQ
 * 					RDR						SIMPLE_CMD					(omit)
 * 	IO_HERE|IO_REDI			RDR			NAME		ARGV
 * 	SYMBOL		FNAME		(omit)		(null)		(null)
 *	(null)		(null)
 */

typedef enum e_type
{
	PIPESEQ = 0,
	CMD,
	RDR,
	SIMPLE_CMD,
	IO_HERE,
	IO_RDR,
	SYMBOL_L,
	SYMBOL_G,
	SYMBOL_DL,
	SYMBOL_DG,
	FNAME,
	NAME,
	ARGV,
	ARG,
}t_type;

typedef enum e_ttype
{
	WORD,
	SYMBOL,
	SQ_WORD,
}t_ttype;

typedef struct	s_ast
{
	t_type	type;
	char	*data;
	struct s_ast	*left;
	struct s_ast	*right;
}t_ast;

typedef struct s_token
{
	t_type	type;
	char	*data;
	struct s_token	*next;
}t_token;

typedef	struct s_box
{
	int		status;
	t_list	*env_lst;
	t_list	*cmd_lst;
}	t_box;

enum	e_pipe
{
	RD_FD = 0,
	WR_FD
};
typedef	struct s_cmd
{
	int		fds[2];
	pid_t	pid;
}	t_cmd;

typedef	enum s_ctype
{
	CD = 0,
	ECHO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
	GENERAL,
	NONE,
}	t_ctype;

#endif
