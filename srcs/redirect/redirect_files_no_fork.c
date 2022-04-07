/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_files_no_fork.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:04:46 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 15:12:15 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	check_sys_err(int ret, char *str)
{
	if (ret < 0)
	{
		print_err(str, NULL, strerror(errno));
		g_box->exit_code = EXIT_FAILURE;
		return (-1);
	}
	return (0);
}

static	int	redirect_r_file(char *fname)
{
	int	f_fd;
	int	ret;

	f_fd = open(fname, O_RDONLY);
	if (check_sys_err(f_fd, fname) < 0)
		return (-1);
	ret = dup2(f_fd, STDIN_FILENO);
	if (check_sys_err(ret, "dup2()") < 0)
		return (-1);
	ret = close(f_fd);
	if (check_sys_err(ret, "close()") < 0)
		return (-1);
	return (0);
}

static	int	redirect_w_file(t_type symbol, char *fname)
{
	int	f_fd;
	int	ret;
	int	oflag;	

	if (symbol == SYMBOL_DG)
		oflag = O_WRONLY | O_CREAT | O_APPEND;
	else
		oflag = O_WRONLY | O_CREAT | O_TRUNC;
	f_fd = open(fname, oflag, 0644);
	if (check_sys_err(f_fd, fname) < 0)
		return (-1);
	ret = dup2(f_fd, STDOUT_FILENO);
	if (check_sys_err(ret, "dup2()") < 0)
		return (-1);
	ret = close(f_fd);
	if (check_sys_err(ret, "close()") < 0)
		return (-1);
	return (0);
}

int	redirect_files_no_fork(t_ast *rdr)
{
	t_type	symbol;
	char	*fname;
	int		ret;

	if (!rdr)
		return (0);
	if (rdr->type == IO_RDR || rdr->type == IO_HERE)
	{
		symbol = rdr->left->type;
		fname = rdr->right->data;
		if (symbol == SYMBOL_L || symbol == SYMBOL_DL)
			ret = redirect_r_file(fname);
		else
			ret = redirect_w_file(symbol, fname);
		if (ret == -1)
			return (-1);
		return (0);
	}
	if (redirect_files_no_fork(rdr->left) < 0)
		return (-1);
	if (redirect_files_no_fork(rdr->right) < 0)
		return (-1);
	return (0);
}
