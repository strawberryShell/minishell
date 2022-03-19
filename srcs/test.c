#include "minishell.h"

void	initiate_box(t_box *box, char **envp)
{
	box = (t_box *)ft_calloc(1, sizeof(t_box));
	while (*envp)
	{
		ft_lstadd_back(box->env_lst, ft_lstnew(ft_strdup(*envp)));
		envp++;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_box	box;
	t_ast	*ast;
	t_ast	*curr_psq;

	// env 리스트 초기화 -> box 초기화로 변경하기
	initiate_box(&box, envp);
	ast = my_ast();
	// exit_code= 127의 의미는? 어디서 가져오지?
	if (argc > 1)
		exit_with_err(argv[1], strerror(ENOENT), 127);
	run_command(&box, ast);
	// t_box안에 있는 cmd_lst free해줘야함. 
	// 그래야 다음 readline에서 새로 받을수 있음.
	// 빌트인이나 아무 cmd가 없을 경우, fd를 모두 원상복귀 시켜야함. (fstat)
	return (0);
}



