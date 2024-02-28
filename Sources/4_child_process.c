/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_child_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:29 by blarger           #+#    #+#             */
/*   Updated: 2024/02/24 10:56:35 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	child_process(t_pipex *pipex, char **envp)
{
	if (dup2(pipex->file->fd1, STDIN_FILENO) == -1)
		return (free_list(pipex), print_error(DUP2));
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		return (free_list(pipex), print_error(DUP2));
	close(pipex->pipefd[0]);
	close(pipex->file->fd1);
	execve(pipex->cmd->bash_path_cmd1, pipex->cmd->cmd1, envp);
}
