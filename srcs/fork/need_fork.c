/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:55 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/04 14:06:55 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	need_fork(t_cmd *prev_cmd, t_ast *tree)
{
	t_ctype	cmd_type;

	cmd_type = which_cmd_type(tree->left->data);
	if (!prev_cmd && !tree->right && cmd_type != GENERAL)
		return (cmd_type);
	return (-1);
}
