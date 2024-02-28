/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:30:02 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 09:00:50 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	check_file_error(t_pipex *pipex)
{
	pipex->file->read_access_1 = true;
	pipex->file->write_access_2 = true;
	pipex->file->exist_file_1 = true;
	pipex->file->exist_file_2 = true;
	if (access(pipex->file->filename1, F_OK))
		pipex->file->exist_file_1 = false;
	if (access(pipex->file->filename2, F_OK))
		pipex->file->exist_file_2 = false;
	else if (access(pipex->file->filename1, R_OK))
		pipex->file->read_access_1 = false;
	if (access(pipex->file->filename2, W_OK))
		pipex->file->write_access_2 = false;
}

void	message(char *msg, char *comp)
{
	msg = ft_strjoin(msg, comp);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	free(msg);
}

void	command_error(t_pipex *pipex, int n)
{
	if (n == 1)
		pipex->cmd->valid_cmd1 = false;
	else
		pipex->cmd->valid_cmd2 = false;
}

void	perms_denied(t_pipex *pipex)
{
	message(PERM, pipex->file->filename1);
	message(PERM, pipex->file->filename2);
}

void	check_error(t_pipex *pipex)
{
	if (pipex->file->exist_file_1 == false
		|| pipex->file->read_access_1 == false
		|| pipex->file->write_access_2 == false
		|| (pipex->cmd->valid_cmd2 == false
			&& pipex->cmd->valid_cmd1 == true))
	{
		print_error_msg(pipex);
	}
	else if (pipex->cmd->valid_cmd1 == false)
	{
		message(COM, pipex->cmd->cmd1[0]);
		return (free_list(pipex), exit(EXIT_SUCCESS));
	}
	if (pipex->cmd->valid_cmd2 == false)
		message(COM, pipex->cmd->cmd2[0]);
	if (pipex->cmd->valid_cmd1 == false
		&& pipex->cmd->valid_cmd2 == false)
		return (free_list(pipex), exit(EXIT_FAILURE));
}
