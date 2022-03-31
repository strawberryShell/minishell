/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tmpfiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:47:13 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/29 17:35:02 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_tmpfiles(void)
{
	DIR				*dir_ptr;
	struct	dirent	*file;
	char			*fname;

	dir_ptr = NULL;
	file = NULL;
	//TODO tmp 저장위치 -> 절대경로로... (논의필요)
	dir_ptr = opendir("/Users/hongsehui/42seoul/minishell/.tmp");
	if (!dir_ptr)
		exit_with_err("opening .tmp directory failed", strerror(errno), EXIT_FAILURE);
	file = readdir(dir_ptr);
	while (file)
	{
		if (!ft_strncmp(file->d_name, "tmpfile-", 8))
		{
			fname = ft_strjoin(".tmp/", file->d_name);
			printf("deleting file %s in .tmp\n", fname);
			unlink(fname);
			free(fname);
			fname = NULL;
		}
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
}