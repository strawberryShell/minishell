#include "minishell.h"

int	is_same_key(char *str, char *key)
{
	int	key_len;

	key_len = ft_strlen(key);
	if (!ft_strncmp(str, key, key_len) && str[key_len] == '=')
		return (1);
	return (0);
}