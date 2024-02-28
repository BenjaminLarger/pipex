/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:26:11 by blarger           #+#    #+#             */
/*   Updated: 2024/02/28 16:57:50 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	redirection_op_using_limiter(t_pipex *pipex, char **argv, char **envp)
{
	open_here_files(pipex, argv);
	read_from_input(pipex, argv);
	read_cmds(pipex, 5, argv + 1, envp);
	if (dup2(pipex->file->fd1, STDIN_FILENO) == -1)
		return (free_list(pipex), print_error(DUP2));
	child_process(pipex, envp, 0);
	if (dup2(pipex->file->fd2, STDOUT_FILENO) == -1)
		return (free_list(pipex), print_error(DUP2));
	execve(pipex->cmds[1].bash_path, pipex->cmds[1].cmd, envp);
}

void	multiple_cmds(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int		i;

	open_file(pipex, argv, argc);
	read_cmds(pipex, argc, argv, envp);
	if (dup2(pipex->file->fd1, STDIN_FILENO) == -1)
		return (free_list(pipex), print_error(DUP2));
	i = -1;
	while (++i < pipex->total_cmd - 1)
		child_process(pipex, envp, i);
	dup2(pipex->file->fd2, STDOUT_FILENO);
	execve(pipex->cmds[argc - 4].bash_path, pipex->cmds[argc - 4].cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (print_error(ARG), -1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (print_error(MALLOC_FAIL), -1);
	if (!ft_strncmp(argv[1], "here_doc", 8) && argc == 6)
		return (redirection_op_using_limiter(pipex, argv, envp), 0);
	else
	{
		multiple_cmds(pipex, argc, argv, envp);
	}
}
