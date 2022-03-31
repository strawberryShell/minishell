/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/31 14:05:01 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include "readline/history.h"
# include "readline/readline.h"
# include "ast.h"
# include "builtin.h"
# include "execute.h"
# include "fork.h"
# include "heredoc.h"
# include "libft.h"
# include "parse.h"
# include "redirect.h"
# include "structure.h"
# include "utils.h"

void	enum_into_str(t_type type);

#endif
