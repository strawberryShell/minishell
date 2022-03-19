/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:24:10 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/17 17:25:10 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

void	builtin_export(t_list **env_lst, char **argv);
void	builtin_unset(t_list **env_lst, char **argv);
void    initiate_env_lst(t_list **env_lst, char **envp);
char	*get_env_value(t_list *env_lst, char *key);
void	builtin_env(t_list *env_lst);
int	    is_same_key(char *str, char *key);
void	print_err(char *cmd, char *str1, char *str2);

#endif