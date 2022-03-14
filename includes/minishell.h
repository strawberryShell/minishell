/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/14 15:13:42 by jiskim           ###   ########.fr       */
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

void	parse_line(char *line_read);
void	parse(char *line);

#endif
