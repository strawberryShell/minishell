/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_echoctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:03:11 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/08 22:11:50 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 안보이게 ^C
void	off_echoctl(void)
{
	struct termios	term_attr;

	tcgetattr(STDIN_FILENO, &term_attr);
	term_attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);
}

//terminal - 제어문자 보이게
void	on_echoctl(void)
{
	struct termios	term_attr;

	tcgetattr(STDIN_FILENO, &term_attr);
	term_attr.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);
}
