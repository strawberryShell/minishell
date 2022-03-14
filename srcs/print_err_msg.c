/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:22:22 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/15 08:22:24 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_err_msg(char *cmd, char *str1, char *str2)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	if (str1)
	{	
		ft_putstr_fd(str1, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(str2, 2);	
}