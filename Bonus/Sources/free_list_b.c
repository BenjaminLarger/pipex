/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:17:05 by blarger           #+#    #+#             */
/*   Updated: 2024/02/23 15:21:11 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	free_list(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	if (pipex->file->filename1)
		free(pipex->file->filename1);
	if (pipex->file->filename2)
		free(pipex->file->filename2);
	while (i < pipex->total_cmd)
	{
		j = 0;
		while (j < pipex->cmds[i].n_cmd)
		{
			free(pipex->cmds[i].cmd[j]);
			j++;
		}
		free(pipex->cmds[i].cmd);
		free(pipex->cmds[i].bash_path);
		i++;
	}
	free(pipex->cmds);
	free(pipex->file);
	free(pipex);
}
