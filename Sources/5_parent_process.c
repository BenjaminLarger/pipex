/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_parent_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:26:24 by blarger           #+#    #+#             */
/*   Updated: 2024/02/24 10:56:39 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	parent_process(t_pipex *pipex, char **envp)
{
	pid_t	terminated_pid;
	int		status;

	terminated_pid = waitpid(pipex->child_pid, &status, 0);
	if (terminated_pid < 0)
		return (free_list(pipex), print_error(WAIT));
	if (WIFEXITED(status))
	{
		if (dup2(pipex->file->fd2, STDOUT_FILENO) == -1)
			return (free_list(pipex), print_error(DUP2));
		if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
			return (free_list(pipex), print_error(DUP2));
		close(pipex->pipefd[1]);
		close(pipex->file->fd2);
		execve(pipex->cmd->bash_path_cmd2, pipex->cmd->cmd2, envp);
	}
	if (WIFSIGNALED(status))
		return (free_list(pipex), print_error(CHILD));
}
