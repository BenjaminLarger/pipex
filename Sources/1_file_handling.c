/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_file_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:29:05 by blarger           #+#    #+#             */
/*   Updated: 2024/02/28 09:56:53 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	open_file(t_pipex *pipex, char *file1, char *file2)
{
	pipex->file = malloc(sizeof(t_file));
	if (!pipex->file)
		return (free(pipex), print_error (MALLOC_FAIL));
	pipex->file->fd1 = open(file1, O_RDWR);
	pipex->file->fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->file->filename1 = ft_strdup(file1);
	pipex->file->filename2 = ft_strdup(file2);
	if (!pipex->file->filename1 || !pipex->file->filename2)
		return (free_list(pipex), print_error(MALLOC_FAIL));
}
