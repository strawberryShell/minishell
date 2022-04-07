/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:03:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/04/07 22:08:57 by sehhong          ###   ########.fr       */
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
	// box->row = tgetnum("li");
	// box->col = tgetnum("co");
	// printf("row = %d\ncol = %d\n", box->row, box->col);
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

//커서 위치 가져오기
void	get_cursor_pos(int *x, int *y)
{
	struct termios	term_attr;
	struct termios	restore;

	tcgetattr(STDIN_FILENO, &term_attr);
	tcgetattr(STDIN_FILENO, &restore);
	term_attr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);;
	write(STDIN_FILENO, "\033[6n", 4);
	*x = get_coordinate(';');
	*y = get_coordinate('R');
	tcsetattr(0, TCSANOW, &restore);
	printf("row = %d, col = %d\n", *x, *y);
}

//커서 한줄 위로 이동 -> up

//커서 얼마만큼 뒤로 이동 -> cm

//커서 맨앞으로 이동하고 그 이후 지움 -> cm, ce

//커서 지우기 -> cm, ce
