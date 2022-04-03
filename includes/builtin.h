/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/04/01 22:40:28 by jiskim           ###   ########.fr       */
=======
/*   Updated: 2022/04/03 01:11:26 by sehhong          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "structure.h"

int	ft_cd(t_list *env_list, char **argv);
int	ft_echo(char **argv);
int	ft_env(t_list *env_list, char **argv);
int	ft_exit(t_box *box, char **argv, int *if_exit);
int	ft_export(t_list **env_list, char **argv);
int	ft_pwd(char **argv);
int	ft_unset(t_list **env_list, char **argv);

/* print_err */
void	print_err(char *cmd, char *str1, char *str2);
void	print_err2(char *cmd, char *str1, char *str2);

/* utils */
char	*get_env(t_list *env_list, char *key);
int	is_same_key(char *str, char *key);
int	is_option(char *str, char *cmd);

#endif
