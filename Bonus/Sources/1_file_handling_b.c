/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_file_handling_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:29:05 by blarger           #+#    #+#             */
/*   Updated: 2024/02/28 17:02:10 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

static void	write_to_fd1(t_pipex *pipex, char **argv);

void	open_file(t_pipex *pipex, char **argv, int argc)
{
	pipex->file = malloc(sizeof(t_file));
	if (!pipex->file)
		return (free(pipex->file), free(pipex), print_error (MALLOC_FAIL));
	pipex->file->fd1 = open(argv[1], O_RDWR);
	pipex->file->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->file->filename1 = ft_strdup(argv[1]);
	pipex->file->filename2 = ft_strdup(argv[argc - 1]);
	if (!pipex->file->filename1 || !pipex->file->filename2)
		return (free_list(pipex), print_error(MALLOC_FAIL));
	check_file_error(pipex);
}

void	open_here_files(t_pipex *pipex, char **argv)
{
	pipex->file = malloc(sizeof(t_file));
	if (!pipex->file)
		return (free(pipex), print_error(MALLOC_FAIL));
	pipex->file->filename1 = ft_strdup("pipex_doc");
	pipex->file->filename2 = ft_strdup(argv[5]);
	pipex->file->fd1 = open (pipex->file->filename1, O_CREAT
			| O_RDWR | O_TRUNC, 0644);
	pipex->file->fd2 = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (!pipex->file->filename1 || !pipex->file->filename2)
		return (free_list(pipex), print_error(MALLOC_FAIL));
	check_file_error(pipex);
}

void	read_from_input(t_pipex *pipex, char **argv)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		buffer = get_next_line(STDIN_FILENO);
		pipex->file->limited = ft_strjoin_free(pipex->file->limited, buffer);
		free(buffer);
		if (ft_strstr(pipex->file->limited, argv[2]))
			break ;
	}
	write_to_fd1(pipex, argv);
}

static void	write_to_fd1(t_pipex *pipex, char **argv)
{
	int		i;
	int		limit_len;

	limit_len = ft_strlen(argv[2]);
	i = 0;
	while (i < ft_strlen(pipex->file->limited))
		i++;
	while (limit_len >= 0)
	{
		pipex->file->limited[--i] = '\0';
		limit_len--;
	}
	write(pipex->file->fd1, pipex->file->limited,
		ft_strlen(pipex->file->limited));
	close(pipex->file->fd1);
	open(pipex->file->filename1, O_RDONLY);
	free(pipex->file->limited);
}
