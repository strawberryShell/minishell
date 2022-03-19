/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exeve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehhong <sehhong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:48:39 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/19 12:21:28 by sehhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd, echo, env, exit, export, pwd, unset
t_bltn test_builtin(char *name)
{
    t_bltn  ret;
    
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
        ret = NON_BLTN;
    return (ret);
}

void    run_builtin(t_bltn bltn, t_ast *s_cmd)
{
    char    *name;
    t_ast   *curr_argv;
    char    **argv;

    name = s_cmd->left->data;
    curr_argv = s_cmd->right;
    // 문자열 배열 생성
    while (curr_argv)
    {
        ast_to_array();
        curr_argv = curr_argv->right;
    }
    
}

void    run_execve(t_box *box, t_ast s_cmd)
{
    
}

void    run_cmd(t_ast *cmd)
{
    t_builtin   builtin;

    builtin = test_builtin(cmd->data);
    if (builtin == NON_BUILTIN)
        run_execve();
    else
        run_builtin(bltn, cmd->right->)  
}