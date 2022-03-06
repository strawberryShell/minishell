#include "minishell.h"

int	count_cmds(char **arr_cmds)
{
	int	num_of_cmds;

	num_of_cmds = 0;
	while (*arr_cmds++)
		num_of_cmds++;
	return (num_of_cmds);
}

// ft_split에서 일어난 에러를 메인에 알려야 하나..?
void	parse_line(char *line_read)
{
    char	**arr_cmds;
	int		num_of_cmd;
	
	arr_cmds = ft_split(line_read, '|');
	num_of_cmd = count_cmds(arr_cmds);
	// argv 치환하기(파싱) : $PATH, '$PATH', "$PATH" ...
	// cmd 1개일때
	if (num_of_cmd == 1)
	{
		//리다이렉션 설정 (<, << , >, >>)
		//builtin 또는 execve 실행
		//$? update
	}
	else	//cmd 1개 이상일때
	{	
		//multi-pipe (while문으로 돌릴때 각 cmd에 대하여)
		//리다이렉션 설정 (<, << , >, >>)
		//다중 파이프 연결
		//builtin 또는 exeve 실행
		//wait
		//$? update
	}
}