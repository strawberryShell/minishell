/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:30:37 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 15:33:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    make_argv(t_box *box, char *arg)
{
    t_cmd	*curr_cmd;

	curr_cmd = (t_cmd*)(ft_lstlast(box->cmd_lst)->content);
    extend_argv(curr_cmd, arg);
}