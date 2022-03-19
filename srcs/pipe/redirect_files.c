/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:21:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/19 22:21:57 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	redirect_r_files(char *fname)
{
	int	f_fd;

	f_fd = ft_open(fname, O_RDONLY, 0);
	ft_dup2(f_fd, STDIN_FILENO);
	ft_close(f_fd);
}

static	void	redirect_w_file(char *symbol, char *fname)
{
	int	f_fd;

	if (*(++symbol) == '>')
		f_fd = ft_open(fname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		f_fd = ft_open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_dup2(f_fd, STDOUT_FILENO);
	ft_close(f_fd);
}

void    redirect_files(t_ast *io)
{
    char	*symbol;
	char	*fname;
	int		f_fd;

	symbol = (char *)(io->left->data);
	fname = (char *)(io->right->data);
	if (*symbol == '<')		// < , <<
		redirect_r_fd(fname);
	else	// > , >>
		redirect_w_fd(symbol, fname);
}