/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:33:51 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 08:57:32 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

static void	fail_commands(t_pipex *pipex)
{
	if (pipex->file->exist_file_1 == false)
	{
		message(FILE, pipex->file->filename1);
		if (pipex->file->write_access_2 == false)
			message(PERM, pipex->file->filename2);
		else
			perror(pipex->cmd->cmd2[0]);
	}
	else if (pipex->file->read_access_1 == false
		&& pipex->file->write_access_2 == true)
	{
		message(PERM, pipex->file->filename1);
		message(COM, pipex->cmd->cmd2[0]);
	}
	else if (pipex->file->read_access_1 == true
		&& pipex->file->write_access_2 == false)
	{
		message(COM, pipex->cmd->cmd1[0]);
		message(PERM, pipex->file->filename2);
	}
	else if (pipex->file->read_access_1 == false
		&& pipex->file->write_access_2 == false)
		perms_denied(pipex);
	return (free_list(pipex), exit(EXIT_FAILURE));
}

static void	fail_command2(t_pipex *pipex)
{
	if (pipex->file->exist_file_1 == false
		&& pipex->file->write_access_2 == false)
		fail_commands(pipex);
	else if (pipex->file->exist_file_1 == false
		&& pipex->file->write_access_2 == true)
	{
		message(FILE, pipex->file->filename1);
		message(COM, pipex->cmd->cmd2[0]);
	}
	else if (pipex->file->read_access_1 == false
		&& pipex->file->write_access_2 == false)
		fail_commands(pipex);
	else if (pipex->file->read_access_1 == true
		&& pipex->file->write_access_2 == false)
		perror(pipex->file->filename2);
	else if (pipex->file->read_access_1 == false
		&& pipex->file->write_access_2 == true)
		fail_commands(pipex);
	else
	{
		message(COM, pipex->cmd->cmd2[0]);
	}
	return (free_list(pipex), exit(EXIT_FAILURE));
}

static void	fail_command1(t_pipex *pipex)
{
	if (pipex->file->exist_file_1 == false
		&& pipex->file->write_access_2 == false)
		fail_commands(pipex);
	else if (pipex->file->exist_file_1 == false
		&& pipex->file->write_access_2 == true)
	{
		message(FILE, pipex->file->filename1);
		return (free_list(pipex), exit(EXIT_SUCCESS));
	}
	else if (pipex->file->read_access_1 == false
		&& pipex->file->write_access_2 == false)
		fail_commands(pipex);
	else if (pipex->file->read_access_1 == true
		&& pipex->file->write_access_2 == false)
		fail_commands(pipex);
	else if (pipex->file->read_access_1 == false
		&& pipex->file->write_access_2 == true)
	{
		message(PERM, pipex->file->filename1);
		return (free_list(pipex), exit(EXIT_SUCCESS));
	}
}

static void	fail_exist(t_pipex *pipex)
{
	if (pipex->file->exist_file_2 == false)
	{
		message(FILE, pipex->file->filename1);
		return (free_list(pipex), exit(EXIT_SUCCESS));
	}
	else if (pipex->file->write_access_2 == false)
		fail_commands(pipex);
	else if (pipex->file->write_access_2 == true)
	{
		message(FILE, pipex->file->filename1);
		return (free_list(pipex), exit(EXIT_SUCCESS));
	}
	return (free_list(pipex), exit(EXIT_FAILURE));
}

void	print_error_msg(t_pipex *pipex)
{
	if (pipex->cmd->valid_cmd2 == false
		&& pipex->cmd->valid_cmd1 == false)
		fail_commands(pipex);
	else if (pipex->cmd->valid_cmd2 == false
		&& pipex->cmd->valid_cmd1 == true)
		fail_command2(pipex);
	else if (pipex->cmd->valid_cmd2 == true
		&& pipex->cmd->valid_cmd1 == false)
		fail_command1(pipex);
	else if (pipex->file->exist_file_1 == false)
		fail_exist(pipex);
	else if (pipex->file->read_access_1 == false)
	{
		if (pipex->file->write_access_2 == false)
			fail_commands(pipex);
		message(PERM, pipex->file->filename1);
		return (free_list(pipex), exit(EXIT_SUCCESS));
	}
	else if (pipex->file->write_access_2 == false)
	{
		message(PERM, pipex->file->filename2);
	}
	return (free_list(pipex), exit(EXIT_FAILURE));
}
