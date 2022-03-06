/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/06 16:24:56 by jiskim           ###   ########.fr       */
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
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

void	parse_line(char *line_read);
char    **ft_split(char const *str, char c);

#endif
