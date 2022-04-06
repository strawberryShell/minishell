/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/05 15:37:30 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		ft_cd(t_list *env_list, char **argv);
int		ft_echo(char **argv);
int		ft_env(t_list *env_list, char **argv);
int		ft_exit(t_box *box, char **argv, int *if_exit);
int		ft_export(t_list **env_list, char **argv);
int		ft_pwd(char **argv);
int		ft_unset(t_list **env_list, char **argv);

/* print_err */
void	print_err(char *cmd, char *str1, char *str2);
void	print_err2(char *cmd, char *str1, char *str2);

/* utils */
char	*get_env(t_list *env_list, char *key);
int		is_same_key(char *str, char *key);
int		is_valid_key(char *str);
int		is_option(char *str, char *cmd);

#endif
