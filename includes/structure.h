/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:31:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/04/08 18:29:43 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

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
	ARG
}t_type;

typedef enum e_ttype
{
	WORD = 0,
	PIPE,
	SYMBOL,
	SYMBOL_HERE
}t_ttype;

typedef struct s_ast
{
	t_type			type;
	char			*data;
	struct s_ast	*left;
	struct s_ast	*right;
}t_ast;

typedef struct s_token
{
	t_ttype			type;
	char			*data;
	struct s_token	*next;
}t_token;

typedef struct s_box
{
	int		exit_code;
	int		h_flag;
	t_list	*env_list;
	t_list	*cmd_list;
}	t_box;

enum	e_pipe
{
	RD_FD = 0,
	WR_FD
};

typedef struct s_cmd
{
	int		fds[2];
	pid_t	pid;
}	t_cmd;

typedef enum s_ctype
{
	CD = 0,
	EHCO,
	ENV,
	EXIT,
	EXPORT,
	PWD,
	UNSET,
	GENERAL,
	NONE,
}	t_ctype;

#endif
