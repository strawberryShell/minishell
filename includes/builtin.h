/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 16:05:23 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "structure.h"

int	builtin_cd(t_list *env_lst, char **argv);
int	builtin_echo(char **argv);
int	builtin_env(t_list *env_lst);
int	builtin_exit(char **argv);
int	builtin_export(t_list **env_lst, char **argv);
int	builtin_pwd(void);
int	builtin_unset(t_list **env_lst, char **argv);

/* print_err */
void	print_err(char *cmd, char *str1, char *str2);
void	print_err2(char *cmd, char *str1, char *str2);

/* utils */
char	*get_env_value(t_list *env_lst, char *key);
int	is_same_key(char *str, char *key);
int	is_special_var(char *var);

#endif