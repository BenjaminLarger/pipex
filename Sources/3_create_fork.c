/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_create_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:15:57 by blarger           #+#    #+#             */
/*   Updated: 2024/02/21 17:02:43 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	create_fork(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) == -1)
		return (free_list(pipex), print_error(PIPE));
	pipex->child_pid = fork();
	if (pipex->child_pid < 0)
		return (free_list(pipex), print_error(FORK));
}
