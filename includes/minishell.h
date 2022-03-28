/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 16:28:47 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "readline/history.h"
# include "readline/readline.h"
# include "libft.h"
# include "parse.h"
# include "builtin.h"
# include "execute.h"
# include "fork.h"
# include "redirection.h"
# include "structure.h"

void	enum_into_str(t_type type);
void    print_preorder(t_ast *tree);
t_ast   *my_ast(void);

void	exit_with_err(char *str1, char *str2, int exit_code);
void	free_ptr(void **ptr);
void	read_ast(t_box *box, t_ast *tree);
int		ft_open(char *fname, int oflag, int mode);
void	ft_close(int fd);
void	ft_dup2(int fd1, int fd2);
void    ft_pipe(int *fds);
pid_t	ft_fork(void);

#endif
