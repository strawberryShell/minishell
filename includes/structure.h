/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:31:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/15 20:46:55 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

/*
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
	t_ttype			type;
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

typedef	struct s_box
{
	t_list	*env_lst;
	int		num_of_cmd;
	int		**pipe_fds;
	pid_t	*child_pids;
}	t_box;

enum	e_pipe
{
	PIPE_RD_FD = 0,
	PIPE_WR_FD
};

#endif
