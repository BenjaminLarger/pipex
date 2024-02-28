/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:17:05 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 08:49:29 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	free_list(t_pipex *pipex)
{
	int	i;

	i = 0;
	free(pipex->file->filename1);
	free(pipex->file->filename2);
	while (pipex->cmd->cmd1[i])
	{
		free(pipex->cmd->cmd1[i]);
		i++;
	}
	free(pipex->cmd->cmd1);
	i = 0;
	while (pipex->cmd->cmd2[i])
	{
		free(pipex->cmd->cmd2[i]);
		i++;
	}
	free(pipex->cmd->bash_path_cmd1);
	free(pipex->cmd->bash_path_cmd2);
	free(pipex->cmd->cmd2);
	free(pipex->cmd);
	free(pipex->file);
	free(pipex);
}

void	print_error(char *str)
{
	return (ft_putstr_fd(str, 2), exit(EXIT_FAILURE));
}
