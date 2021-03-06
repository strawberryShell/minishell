/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/13 18:09:46 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define SYNTAX_ERR 258
# define SH_IMG "\n                          ▓▓▓▓  ▓▓▓▓\n\
                        ██▒▒▒▒██▓▓░░████████\n\
                        ██░░░░░░▒▒██▒▒▒▒▒▒  ██\n\
    ░░  ░░░░    ░░  ░░    ██░░░░██▒▒▒▒  ▒▒▒▒▒▒██      ░░░░          ░░\n\
                        ██░░░░░░░░██▒▒▒▒▒▒▒▒▒▒▒▒██\n\
                      ██░░░░██░░▒▒██▒▒▒▒▒▒▒▒▒▒▒▒██\n\
    ░░  ░░░░    ░░  ░░░░████▒▒████▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒██  ░░░░          ░░\n\
                        ██░░▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n\
    ░░    ░░        ░░  ██▒▒▒▒  ▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒██  ░░░░          ░░\n\
                        ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒██\n\
                          ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n\
                            ██  ▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒██\n\
                              ████▒▒▒▒▒▒▒▒  ▒▒██\n\
                                  ████████████\n\n\
    ░░  ░░░░    ░░░░░░      ░░  ░░░░      ░░  ░░      ░░░░  ░░      ░░\n\
     _                      _                                _          _ _\n\
 ___| |_ _ __ __ ___      _| |__   ___ _ __ _ __ _   _   ___| |__   ___| | |\n\
/ __| __| '__/ _` \\ \\ /\\ / / '_ \\ / _ \\ '__| '__| | | | / __| '_ \\ / _ \\\
 | |\n\\__ \\ |_| | | (_| |\\ V  V /| |_) |  __/ |  | |  | |_| | \\__ \\ | | |  \
__/ | |\n|___/\\__|_|  \\__,_| \\_/\\_/ |_.__/ \\___|_|  |_|   \\__, | \
|___/_| |_|\\___|_|_|\n                                                 \
|___/                        \n\n"

# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "libft.h"
# include "structure.h"
# include "ast.h"
# include "builtin.h"
# include "execute.h"
# include "fork.h"
# include "heredoc.h"
# include "parse.h"
# include "redirect.h"
# include "tc_signal.h"
# include "utils.h"

extern t_box	*g_box;

#endif
