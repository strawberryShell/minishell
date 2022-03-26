/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 18:26:28 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "structure.h"

void    builtin_cd(t_list *env_lst, char **argv);
void    builtin_echo(char **argv);
void    builtin_exit(char **argv);
void	builtin_export(t_list **env_lst, char **argv);
void    builtin_pwd(void);
void	builtin_unset(t_list **env_lst, char **argv);
char	*get_env_value(t_list *env_lst, char *key);
void	builtin_env(t_list *env_lst);
int	    is_same_key(char *str, char *key);
void	print_err(char *cmd, char *str1, char *str2);

#endif