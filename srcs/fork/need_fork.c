/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:20:55 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/08 21:53:15 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	need_fork(t_cmd *prev_cmd, t_ast *tree)
{
	t_ctype	cmd_type;

	// c type 정해짐
	cmd_type = which_cmd_type(tree->left->data);
	// NONE도 BUILTIN도 아닌 경우가 GENERAL
	if (!prev_cmd && !tree->right && cmd_type != GENERAL)
		return (cmd_type);
	return (-1);
}
