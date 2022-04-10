/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:07:41 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/09 14:52:51 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TC_SIGNAL_H
# define TC_SIGNAL_H

# include <sys/ioctl.h>

void	control_sigint(int signum);
void	ignore_signal(int signum);

void	off_echoctl(void);
void	on_echoctl(void);

#endif