/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:26:11 by blarger           #+#    #+#             */
/*   Updated: 2024/02/28 09:38:53 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (print_error(ARG), -1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (print_error(MALLOC_FAIL), -1);
	open_file(pipex, argv[1], argv[4]);
	read_cmds(pipex, argv[2], argv[3], envp);
	create_fork(pipex);
	if (pipex->child_pid == 0)
		child_process(pipex, envp);
	else
		parent_process(pipex, envp);
	free_list(pipex);
}
