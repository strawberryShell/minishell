/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:11:31 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/14 17:05:11 by sehhong          ###   ########.fr       */
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

// builtin 
void	builtin_export(t_list **env_lst, char **argv);
void	builtin_unset(t_list **env_lst, char **argv);
void    initiate_env_lst(t_list **env_lst, char **envp);
char	*get_env_value(t_list *env_lst, char *key);
void	builtin_env(t_list *env_lst);

// parse

//utils
void	print_err_msg(char *cmd, char *str1, char *str2);
int	is_same_key(char *str, char *key);

#endif
