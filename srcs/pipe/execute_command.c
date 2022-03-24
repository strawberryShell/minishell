/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:48:39 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/24 17:01:22 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	**get_envp(t_box box)
{
	t_list	*env_lst;
	char	**new_envp;

	env_lst = box.env_lst;
	new_envp = (char **)ft_calloc(ft_lstsize(env_lst) + 1, sizeof(char *));
	while (env_lst)
	{
		*new_envp = (char *)(env_lst->content);
		new_envp++;
		env_lst = env_lst->next;
	}
	return (new_envp);
}

// cd, echo, env, exit, export, pwd, unset
static	t_builtin test_builtin(char *name)
{
    t_builtin  ret;
    
    if (!name)
		ret = NONE;
	else if (!ft_strncmp(name, "cd", 3))
        ret = CD;
    else if (!ft_strncmp(name, "echo", 5))
        ret = ECHO;
    else if (!ft_strncmp(name, "env", 4))
        ret = ENV;
    else if (!ft_strncmp(name, "exit", 5))
        ret = EXIT;
    else if (!ft_strncmp(name, "export", 7))
        ret = EXPORT;
    else if (!ft_strncmp(name, "pwd", 4))
        ret = PWD;
    else if (!ft_strncmp(name, "unset", 6))
        ret = UNSET;
	else
        ret = GENERAL;
    return (ret);
}

static	void    run_builtin(t_box *box, t_builtin b_type)
{
    t_list	*env_lst;
	char	**argv;
	int		exit_code;

	env_lst = box->env_lst;
	argv = box->cmd_lst->content->argv;
	if (b_type == CD)
		exit_code = builtin_cd();
	else if (b_type == ECHO)
		exit_code = builtin_echo();
	else if (b_type == ENV)
		exit_code = builtin_exit();
	else if (b_type == EXIT)
		exit_code = builtin_exit();
	else if (b_type == EXPORT)
		exit_code = builtin_export();
	else if (b_type == PWD)
		exit_code = builtin_pwd();
	else
		exit_code = builtin_unset();
	exit(exit_code);
}


// 여기까지 온거면 무조건 포크를 떠야함.
void    execute_command(t_box *box, char *cmd_name)
{
	t_cmd		*curr_cmd;
	t_builtin	b_type;

	curr_cmd = (t_cmd*)(ft_lstnew(box->cmd_lst)->content);
	b_type = test_builtin(cmd_name);
	if (b_type == NONE)
		exit(EXIT_SUCCESS);
	else if (b_type == GENERAL)
	{
		execve(curr_cmd->abs_path, curr_cmd->argv, get_envp(*box));
		exit_with_err("something is wrong with execve", curr_cmd->argv[0], 1);
		// 해당 exit코드는 해보면서 추가한다.
		// if (errno == EACCES)
		// 	exit_with_err("permission denied", argv[0], 126);
		// else
		// 	exit_with_err(strerror(errno), argv[0], EXIT_FAILURE);
	}
	else
		run_builtin(box, b_type);
}