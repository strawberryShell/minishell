#include "minishell.h"

static	int	deallocate(char **str, int max)
{
	int	i;

	i = 0;
	while (i < max)
		free(str[i++]);
	free(str);
	return (1);
}

static int	count_substr(char *str, char c)
{
	int	num_of_substr;
	int	substr_len;

	substr_len = 0;
	num_of_substr = 0;
	while (*str)
	{
		if (*str != c)
			substr_len++;
		else if (substr_len)
		{
			num_of_substr++;
			substr_len = 0;
		}
		str++;
	}
	if (substr_len)
		num_of_substr++;
	return (num_of_substr);
}

static	void	strcpy_until_char(char *dest, char *src, char c)
{
	while (*src && *src != c)
		*dest++ = *src++;
	*dest = '\0';
}

static int	fill_arr_with_strs(char **arr_substrs, char *str, char c)
{
	int		i;
	int		idx;

	idx = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			i = 0;
			while (str[i] && str[i] != c)
				i++;
			arr_substrs[idx] = (char *)malloc(sizeof(char) * (i + 1));
			if (!arr_substrs)
				return (deallocate(arr_substrs, idx));
			strcpy_until_char(arr_substrs[idx], str, c);
			idx++;
			str += i;
		}
	}
	return (0);
}

char    **ft_split(char *str, char c)
{
	char	**arr_substrs;
	int		num_of_substr;

	if (!str)
		return (NULL);
	num_of_substr = count_substr(str, c);
	arr_substrs = (char **)malloc(sizeof(char *) * (num_of_substr + 1));
	if (!arr_substrs)
		return (NULL);
	arr_substrs[num_of_substr] = 0;
	if (fill_arr_with_strs(arr_substrs, str, c))
		return (NULL);
	return (arr_substrs);
}