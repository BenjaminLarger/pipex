/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:08:53 by blarger           #+#    #+#             */
/*   Updated: 2024/02/23 15:19:39 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

static char	*delete_quote(char *str, t_pipex *pipex)
{
	int		i;
	char	*copy;

	if (str[0] != '\'' && str[ft_strlen(str) - 1] != '\'')
		return (str);
	copy = malloc(ft_strlen(str) * sizeof(char));
	if (!copy)
		return (free_list(pipex), print_error(MALLOC_FAIL), NULL);
	i = 1;
	while (i < ft_strlen(str) - 1)
	{
		copy[i - 1] = str[i];
		i++;
	}
	free(str);
	return (copy);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	in_word = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**split_main(char const *s, char **arr, int *start)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (*start < ft_strlen(s))
	{
		if (s[*start] != ' ')
		{
			end = *start;
			while (s[end] != '\0' && s[end] != ' ')
				end++;
			arr[i] = ft_substr(s, *start, end - *start);
			if (!arr[i])
				return (0);
			i++;
			*start = end;
		}
		if (s[*start] == ' ')
			(*start)++;
	}
	arr[i] = NULL;
	return (arr);
}

static char	**init_split(char const *s, char **arr, t_pipex *pipex, char c)
{
	int		start;

	start = 0;
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 3));
	if (!arr)
		return (free_list(pipex), print_error(MALLOC_FAIL), NULL);
	return (split_main(s, arr, &start));
}

char	**ft_split_cmds(char const *s, char c, t_pipex *pipex, int index)
{
	char	**arr;
	int		i;

	arr = NULL;
	arr = init_split(s, arr, pipex, c);
	i = 0;
	while (arr[i])
	{
		arr[i] = delete_quote(arr[i], pipex);
		i++;
	}
	pipex->cmds[index].n_cmd = i;
	return (arr);
}
