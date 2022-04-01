/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/29 17:17:44 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "structure.h"

int	ft_cd(t_list *env_lst, char **argv);
int	ft_echo(char **argv);
int	ft_env(t_list *env_lst);
int	ft_exit(char **argv, int *not_exit);
int	ft_export(t_list **env_lst, char **argv);
int	ft_pwd(void);
int	ft_unset(t_list **env_lst, char **argv);

/* print_err */
void	print_err(char *cmd, char *str1, char *str2);
void	print_err2(char *cmd, char *str1, char *str2);

/* utils */
char	*get_env(t_list *env_lst, char *key);
int	is_same_key(char *str, char *key);
int	is_special_var(char *var);

#endif