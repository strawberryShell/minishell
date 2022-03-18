
#ifndef BUILTIN_H
# define BUILTIN_H

void    builtin_cd(t_list *env_lst, char **argv);
void    builtin_echo(char **argv);
void    builtin_exit(char **argv);
void	builtin_export(t_list **env_lst, char **argv);
void    builtin_pwd(void);
void	builtin_unset(t_list **env_lst, char **argv);
void    initiate_env_lst(t_list **env_lst, char **envp);
char	*get_env_value(t_list *env_lst, char *key);
void	builtin_env(t_list *env_lst);
void	print_blt_err(char *cmd, char *str1, char *str2);
int	    is_same_key(char *str, char *key);

#endif