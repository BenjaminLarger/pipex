/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:40:09 by blarger           #+#    #+#             */
/*   Updated: 2024/02/20 15:49:12 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdbool.h>

typedef struct s_cmd
{
	char	**cmd1;
	char	**cmd2;
	char	*bash_path_cmd1;
	char	*bash_path_cmd2;
	int		n_cmd1;
	int		n_cmd2;
	bool	valid_cmd1;
	bool	valid_cmd2;
}	t_cmd;

typedef struct s_file
{
	int		fd1;
	int		fd2;
	char	*filename1;
	char	*filename2;
	bool	exist_file_1;
	bool	exist_file_2;
	bool	read_access_1;
	bool	write_access_2;
}	t_file;

typedef struct s_pipex
{
	t_file	*file;
	t_cmd	*cmd;
	int		pipefd[2];
	pid_t	child_pid;
	int		fd_child;
	int		fd_father;
}	t_pipex;

#endif