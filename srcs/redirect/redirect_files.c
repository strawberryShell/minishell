/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:21:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 14:15:09 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	redirect_r_file(char *fname)
{
	int	f_fd;

	f_fd = ft_open(fname, O_RDONLY, 0);
	ft_dup2(f_fd, STDIN_FILENO);
	ft_close(f_fd);
}

static	void	redirect_w_file(t_type symbol, char *fname)
{
	int	f_fd;

	if (symbol == SYMBOL_DG)
		f_fd = ft_open(fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		f_fd = ft_open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_dup2(f_fd, STDOUT_FILENO);
	ft_close(f_fd);
}

void	redirect_files(t_ast *rdr)
{
	t_type	symbol;
	char	*fname;

	if (!rdr)
		return ;
	if (rdr->type == IO_RDR || rdr->type == IO_HERE)
	{
		symbol = rdr->left->type;
		fname = rdr->right->data;
		if (symbol == SYMBOL_L || symbol == SYMBOL_DL)
			redirect_r_file(fname);
		else
			redirect_w_file(symbol, fname);
	}
	redirect_files(rdr->left);
	redirect_files(rdr->right);
}
