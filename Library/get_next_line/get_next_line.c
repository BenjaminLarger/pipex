/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:54:29 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 11:57:03 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_buffer(int fd, char *buffer)
{
	char	*copy;
	int		bytes_read;

	copy = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!copy)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (!ft_strchr(copy, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, copy, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(copy), NULL);
		copy[bytes_read] = '\0';
		if (copy[0] != '\0')
			buffer = ft_strcat_mal(buffer, copy);
	}
	return (free(copy), buffer);
}

char	*get_the_line(char *buffer)
{
	char	*newline;
	int		copy_len;
	int		i;

	if (buffer[0] == '\0')
		return (NULL);
	copy_len = 0;
	while (buffer[copy_len] != '\n' && buffer[copy_len] != '\0')
		copy_len++;
	if (buffer[copy_len] == '\n')
		copy_len++;
	newline = ft_calloc((copy_len + 1), sizeof(char));
	if (!newline)
		return (NULL);
	i = 0;
	while (i < copy_len)
	{
		newline[i] = buffer[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*buffer_left(char *buffer)
{
	int		len_buffer;
	int		i;
	char	*new_buffer;

	len_buffer = 0;
	while (buffer[len_buffer] != '\0' && buffer[len_buffer] != '\n')
		len_buffer++;
	if (buffer[len_buffer] == '\0')
		return (free(buffer), NULL);
	if (buffer[len_buffer] == '\n')
		len_buffer++;
	new_buffer = ft_calloc((ft_strlen(buffer) - len_buffer + 1), sizeof(char));
	if (!new_buffer)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[len_buffer] != '\0')
	{
		new_buffer[i] = buffer[len_buffer];
		i++;
		len_buffer++;
	}
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char static	*buffer;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	newline = get_the_line(buffer);
	buffer = buffer_left(buffer);
	return (newline);
}
