/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/04 16:47:16 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// typedef	enum	s_builtin
// {
// 	ECHO, 
// }	e_builtin				

# include <readline/history.h>
# include <readline/readline.h>
# include <sys/errno.h>
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

void	parse_line(char *line_read);
char    **ft_split(char *str, char c);

#endif