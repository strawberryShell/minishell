/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:31:15 by jiskim            #+#    #+#             */
/*   Updated: 2022/03/12 19:06:54 by jiskim           ###   ########.fr       */
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

enum e_type{
	PIPESEQ = 0,
	CMD,
	RDR,
	SIMPLE_CMD,
	IO_HERE,
	IO_REDI,
	SYMBOL_L,
	SYMBOL_G,
	SYMBOL_DL,
	SYMBOL_DG,
	FNAME,
	NAME,
	ARGV,
	ARG,
	WORD
};

struct	s_ast
{
	e_type	type;
	void	*data;
	s_ast	*left;
	s_ast	*right;
};

typedef struct s_token
{
	e_type	type;
	char	*str;
	s_token	*next;
}t_token;

#endif
