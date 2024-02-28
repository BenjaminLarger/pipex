/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_child_process_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:29 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 11:08:02 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

static void	sub_child_process(t_pipex *pipex, int index, char **envp);
static void	sub_parent_process(t_pipex *pipex);

void	child_process(t_pipex *pipex, char **envp, int index)
{
	if (pipe(pipex->pipefd) == -1)
		return (free_list(pipex), print_error(PIPE));
	pipex->child_pid = fork();
	if (pipex->child_pid < 0)
		return (free_list(pipex), print_error(PIPE));
	if (pipex->child_pid == 0)
		sub_child_process(pipex, index, envp);
	else
		sub_parent_process(pipex);
}

static void	sub_child_process(t_pipex *pipex, int index, char **envp)
{
	close(pipex->pipefd[0]);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		return (free_list(pipex), print_error(DUP2));
	execve(pipex->cmds[index].bash_path, pipex->cmds[index].cmd, envp);
	return (free_list(pipex), print_error(""));
}

static void	sub_parent_process(t_pipex *pipex)
{
	int	status;

	waitpid(pipex->child_pid, NULL, 0);
	if (WIFEXITED(status))
	{
		close(pipex->pipefd[1]);
		if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
			return (free_list(pipex), print_error(DUP2));
	}
	else
		return (free_list(pipex), print_error(WAIT));
}
