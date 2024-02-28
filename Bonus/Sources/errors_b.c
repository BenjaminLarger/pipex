/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:30:02 by blarger           #+#    #+#             */
/*   Updated: 2024/02/23 15:14:57 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	check_file_error(t_pipex *pipex)
{
	pipex->file->read_access_1 = true;
	pipex->file->write_access_2 = true;
	pipex->file->exist_file_1 = true;
	if (access(pipex->file->filename1, F_OK))
		pipex->file->exist_file_1 = false;
	else if (access(pipex->file->filename1, R_OK)
		|| access(pipex->file->filename1, W_OK))
		pipex->file->read_access_1 = false;
	if (access(pipex->file->filename2, W_OK))
		pipex->file->write_access_2 = false;
}

void	message(char *msg, char *comp, bool *error)
{
	msg = ft_strjoin(msg, comp);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	free(msg);
	if (ft_strncmp(msg, COM, ft_strlen(COM)))
		*error = true;
}

void	print_error_msg(t_pipex *pipex)
{
	int		i;
	bool	error;

	error = false;
	i = 0;
	while (i < pipex->total_cmd)
	{
		if (pipex->cmds[i].valid_cmd == false)
			message(COM, pipex->cmds[i].cmd[0], &error);
		i++;
	}
	if (pipex->file->exist_file_1 == false)
		message(FILE, pipex->file->filename1, &error);
	if (pipex->file->read_access_1 == false)
		message(PERM, pipex->file->filename1, &error);
	if (pipex->file->write_access_2 == false)
		message(PERM, pipex->file->filename2, &error);
	if (error == true)
		return (free_list(pipex), exit(EXIT_FAILURE));
}
