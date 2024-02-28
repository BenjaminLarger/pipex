/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:40:09 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 10:42:16 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdbool.h>

typedef struct s_cmd
{
	char			**cmd;
	bool			valid_cmd;
	char			*bash_path;
	int				n_cmd;
}	t_cmd;

typedef struct s_file
{
	int		fd1;
	int		fd2;
	int		fd1_limited;
	char	*filename1;
	char	*filename2;
	char	*filename_limited;
	char	*limited;
	bool	exist_file_1;
	bool	read_access_1;
	bool	write_access_2;
}	t_file;

typedef struct s_pipex
{
	t_file	*file;
	int		total_cmd;
	t_cmd	*cmds;
	int		pipefd[2];
	pid_t	child_pid;
	int		fd_child;
	int		fd_father;
	char	**env;
}	t_pipex;

#endif