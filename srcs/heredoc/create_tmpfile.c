/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tmpfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:08:48 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/31 14:23:17 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static  char    *get_tmpfile_name(void)
{
    static  int i;
    char        *tmp_fname;
    char        *num_str;

    num_str = ft_itoa(i);
    // TODO tmp 저장위치 및 작명법 -> 논의필요
    tmp_fname = ft_strjoin("/tmp/tmpfile-", num_str);
    free_ptr((void**)&num_str);
    return (tmp_fname);
}

char    *create_tmpfile(char *lim)
{
    char    *tmp_name;
    int     tmp_fd;
    char    *line_read;
    char    *tmp_str;

    line_read = NULL;
	tmp_name = get_tmpfile_name();
    tmp_fd = open(tmp_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (tmp_fd < 0)
        exit_with_err("failed to create tmpfile", strerror(errno), EXIT_FAILURE);
    while (1)
    {
        line_read = readline("> ");
        if (!ft_strncmp(line_read, lim, ft_strlen(lim) + 1))
            break ;
        // TODO line_read에서 $(환경변수) get_env로 바꿔야함.
        tmp_str = ft_strjoin(line_read, "\n");
        ft_putstr_fd(tmp_str, tmp_fd);
        free_ptr((void**)&tmp_str);
        free_ptr((void**)&line_read);
    }
    free_ptr((void**)&line_read);
    close(tmp_fd);
    return (tmp_name);
}