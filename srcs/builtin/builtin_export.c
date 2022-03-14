#include "minishell.h"

static void	export_no_arg(t_list *env_lst)
{
	char	*equal_ptr;
	char	*ptr;

	while(env_lst)
	{
		ptr = env_lst->content;
		equal_ptr = ft_strchr(ptr, '=');
		printf("declare -x ");
		while(*ptr != '=' && *ptr)
		{	
			printf("%c", *ptr);
			ptr++;
		}
		if (equal_ptr)
			printf("=\"%s\"", ++ptr);
		printf("\n");
		env_lst = env_lst->next;
	}
}

static  int	get_keylen(char *str)
{
	int	key_len;

	key_len = 0;
	while (*str)
	{
		if (*str == '=')
			break ;
		key_len++;
		str++;
	}
	return (key_len);
}

static	void	export_with_arg(t_list **env_lst, char *arg)
{
	t_list	*curr;
	int		key_len;
	char	*data;

	key_len = get_keylen(arg);
	curr = *env_lst;
	while (curr)
	{
		data =(char *)curr->content;
		if (!ft_strncmp(data, arg, key_len) 
			&& (data[key_len] == '\0' || data[key_len] == '='))
		{
			if (arg[key_len] == '=' && ft_strcmp(data, arg))
			{
				free(data);
				curr->content = ft_strdup(arg);
			}
			break ;
		}
	}
	if (!curr)
		ft_lstadd_back(env_lst, ft_lstnew(ft_strdup(arg)));
}

void	builtin_export(t_list **env_lst, char **argv)
{
	argv++;
	if (!*argv)
	{
		export_no_arg(*env_lst);
		return ;
	}
	while (*argv)
	{
		if (**argv == '=')
		{
			ft_putstr_fd("bash: ", 2);
			print_err_msg("export", *argv, "not a valid identifier\n");
		}
		else
			export_with_arg(env_lst, *argv);
		argv++;
	}
}