/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:48:39 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/26 14:39:49 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	**get_envp(t_list *env_lst)
{
	char	**new_envp;

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
    
    // if (!name)
	// 	ret = NONE;
	if (!ft_strncmp(name, "cd", 3))
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

// static	void    run_builtin(t_box *box, t_builtin b_type)
// {
//     t_list	*env_lst;
// 	char	**argv;
// 	int		exit_code;

// 	env_lst = box->env_lst;
// 	argv = box->cmd_lst->content->argv;
// 	if (b_type == CD)
// 		exit_code = builtin_cd();
// 	else if (b_type == ECHO)
// 		exit_code = builtin_echo();
// 	else if (b_type == ENV)
// 		exit_code = builtin_exit();
// 	else if (b_type == EXIT)
// 		exit_code = builtin_exit();
// 	else if (b_type == EXPORT)
// 		exit_code = builtin_export();
// 	else if (b_type == PWD)
// 		exit_code = builtin_pwd();
// 	else
// 		exit_code = builtin_unset();
// 	exit(exit_code);
// }

static	void	execute_command(t_list *env_lst, char *abs_path, char **argv)
{
	t_builtin	b_type;
	int			i;

	b_type = test_builtin(argv[0]);
	// if (b_type == NONE)
	// 	exit(EXIT_SUCCESS);
	if (b_type == GENERAL)
	{
		ft_putendl_fd(abs_path, 2);
		i = 0;
		while (argv[i])
			ft_putendl_fd(argv[i++], 2);
		ft_putendl_fd("-------------", 2);
		execve(abs_path, argv, get_envp(env_lst));
		if (errno == ENOENT)
			exit_with_err(argv[0], "command not found", 127);
		exit_with_err(argv[0], strerror(errno), EXIT_FAILURE);
	}
	// else
		// run_builtin();
}

void	run_command(t_box *box, t_ast *scmd)
{
	char	*abs_path;
	char	**argv;
	
	argv = (char **)ft_calloc(2, sizeof(char *));
	argv[0] = scmd->left->data;
	abs_path = find_abs_path(box->env_lst, scmd->left->data);
	make_argv(&argv, scmd->right);
	execute_command(box->env_lst, abs_path, argv);
}
