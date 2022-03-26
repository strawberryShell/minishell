/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/26 15:41:59 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "structure.h"

int	builtin_cd(t_list *env_lst, char **argv);
int	builtin_echo(char **argv);
int	builtin_exit(char **argv);
int	builtin_export(t_list **env_lst, char **argv);
int	builtin_pwd(void);
int	builtin_unset(t_list **env_lst, char **argv);
char	*get_env_value(t_list *env_lst, char *key);
int	builtin_env(t_list *env_lst);
int	is_same_key(char *str, char *key);
void	print_err(char *cmd, char *str1, char *str2);

#endif