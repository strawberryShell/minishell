/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:03:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/08 01:22:14 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//termcap 초기세팅
void	initial_config(void)
{
	char	*env;

	env = get_env("TERM");
	if (!env)
		env = "xterm";
	tgetent(NULL, env);
	// interroagte capabilities 
	g_box->cm = tgetstr("cm", NULL);
	g_box->ce = tgetstr("ce", NULL);
	g_box->up = tgetstr("up", NULL);
}

static	int	get_coordinate(char delimiter)
{
	int		i;
	char	c;
	char	buf[20];

	i = 0;
	c = 0;
	ft_memset(buf, 0, 20);
	while (c != delimiter)
	{
		read(STDIN_FILENO, &c, 1);
		if (c >= '0' && c <= '9')
			buf[i++] = c;
	}
	return (ft_atoi(buf) - 1);
}

void	get_cursor_pos(int *x, int *y)
{
	struct termios	term_attr;
	struct termios	restore;
	char			*x_int;
	char			*y_int;

	tcgetattr(STDIN_FILENO, &term_attr);
	tcgetattr(STDIN_FILENO, &restore);
	term_attr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);
	write(STDIN_FILENO, "\033[6n", 4);
	*x = get_coordinate(';');
	*y = get_coordinate('R');
	tcsetattr(0, TCSANOW, &restore);
	x_int = ft_itoa(*x);
	y_int = ft_itoa(*y);
	write(1, x_int, ft_strlen(x_int));
	write(1, ",",1);
	write(1, y_int, ft_strlen(y_int));
}

void	action_for_eof(void)
{
	int	x;
	int	y;

	get_cursor_pos(&x, &y);
	x--;
	y += 10;
	tputs(tgoto(g_box->cm, y, x), 1, NULL);
	// printf("row = %d, col = %d\n", x, y);
}
