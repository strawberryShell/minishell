/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tmpfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:47:13 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/02 14:49:38 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_tmpfile(t_ast *rdr)
{
	if (!rdr || rdr->type == SIMPLE_CMD)
		return ;
	if (rdr->type == IO_HERE)
		unlink(rdr->right->data);
	delete_tmpfile(rdr->left);
	delete_tmpfile(rdr->right);
}
