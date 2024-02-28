/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:54:53 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 11:56:48 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <assert.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

char	*ft_concat(char *cat, char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src)
		return (dest);
	while (src[i] != '\0')
	{
		cat[i] = src[i];
		i++;
	}
	while (dest[j] != '\0')
	{
		cat[i] = dest[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	return (cat);
}

char	*ft_strcat_mal(char *dest, char *src)
{
	char	*cat;

	if (!src)
		return (NULL);
	if (!dest)
	{
		dest = ft_calloc((ft_strlen(src) + 2), sizeof(char));
		if (!dest)
			return (NULL);
	}
	cat = ft_calloc((ft_strlen(src) + ft_strlen(dest) + 2), sizeof(char));
	if (!cat)
	{
		return (free(dest), NULL);
	}
	cat = ft_concat(cat, src, dest);
	free(dest);
	return (cat);
}
