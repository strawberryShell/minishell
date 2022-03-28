/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:29:08 by sehhong           #+#    #+#             */
/*   Updated: 2022/03/28 17:44:09 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ast 예제 트리 반환하기
static  t_ast	*create_node(t_type type, char *data)
{
	t_ast	*node;

	node = (t_ast *)malloc(sizeof(t_ast));
	node->type = type;
    if (data)
	    node->data = ft_strdup(data);
    else
        node->data = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static  t_type	cmp_type(char *str)
{
	int	type;

	if (!ft_strncmp(str, ">",2))
		type = SYMBOL_G;
	else if (!strncmp(str, "<", 2))
		type = SYMBOL_L;
	else if (!strncmp(str, ">>", 3))
		type = SYMBOL_DG;
	else
		type = SYMBOL_DL;
	return (type);
}

static  t_ast   *create_rdr_subtree(char **argv)
{
	t_ast	*rdr;
	t_ast	*io;
	t_type	type;

	if (!*argv)
		return (NULL);
	rdr = create_node(RDR, NULL);
	type = cmp_type(*argv);
	io = create_node(type == SYMBOL_DL ? IO_HERE : IO_RDR, NULL);
	io->left = create_node(type, *argv);
	io->right = create_node(FNAME, *(++argv));
	rdr->left = io;
	argv++;
	rdr->right = create_rdr_subtree(argv);
	return (rdr);
}

static  t_ast	*create_argv_subtree(char **cmd_argv)
{
	t_ast	*argv;

	if (!*cmd_argv)
		return (NULL);
	argv = create_node(ARGV, NULL);
	argv->left = create_node(ARG, *cmd_argv);
	cmd_argv++;
	argv->right = create_argv_subtree(cmd_argv);
	return (argv);
}

static  t_ast	*create_scmd_subtree(char **cmd_argv)
{
	t_ast	*s_cmd;

	s_cmd = create_node(SIMPLE_CMD, NULL);
	s_cmd->left = create_node(NAME, *cmd_argv);
	cmd_argv++;
	s_cmd->right = create_argv_subtree(cmd_argv);
	return (s_cmd);
}

static  t_ast	*create_psq_subtree(char **rdr, char **scmd, char *cmd_type)
{
    t_ast	*root;

	root = (t_ast *)malloc(sizeof(t_ast));
    root->type = PIPESEQ;
	root->left = create_node(CMD, cmd_type);
    root->right = 0;
	root->data = NULL;
	root->left->left = create_rdr_subtree(rdr);
	root->left->right = create_scmd_subtree(scmd);
	return (root);
}

void	print_preorder(t_ast *tree)
{
	if (tree)
	{
		printf("type: %d, data %s\n", tree->type, (char*)tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

t_ast   *my_ast(void)
{
	t_ast	*cmd1;
	t_ast	*cmd2;
	t_ast	*cmd3;
	t_ast	*cmd4;
	char	*cmd1_rdr[] = {"<", "a", 0};
	char	*cmd1_scmd[] = {"ls", 0};
	char	*cmd2_rdr[] = {">", "b", ">", "c", 0};
	char	*cmd2_scmd[] = {"pppp", "hi", 0};
	char	*cmd3_rdr[] = {"<", "a", 0};
	char	*cmd3_scmd[] = {"ls", "-al", 0};
	char	*cmd4_rdr[] = {">", "d", ">", "e", 0};
	char	*cmd4_scmd[] = {"grep", "lib", 0};

	cmd1 = create_psq_subtree(cmd1_rdr, cmd1_scmd, "ls");
	cmd2 = create_psq_subtree(cmd2_rdr, cmd2_scmd, "pppp");
	cmd3 = create_psq_subtree(cmd3_rdr, cmd3_scmd, "ls");
	cmd4 = create_psq_subtree(cmd4_rdr, cmd4_scmd, "grep");
	cmd1->right = cmd2;
	cmd2->right = cmd3;
	cmd3->right = cmd4;
    return (cmd1);
}
