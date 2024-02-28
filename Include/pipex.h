/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:07:37 by blarger           #+#    #+#             */
/*   Updated: 2024/02/23 16:15:29 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Library/Libft/libft.h"
# include "../Library/Ft_printf/ft_printf.h"
# include "error.h"
# include "list.h"
# include <stdbool.h>
# define MAX_PATH_LEN 1024

//1_file_handling.c
void	open_file(t_pipex *pipex, char *file1, char *file2);

//2_cmommands.c
void	read_cmds(t_pipex *pipex, char *cmd1, char *cmd2, char **envp);
void	get_script_bash_cmds(t_pipex *pipex, char **envp);
int		find_path_env(t_pipex *pipex, char **splitted_path, char *cmd, int n);

//3_create_fork.c
void	create_fork(t_pipex *pipex);

//4_child_process.c
void	child_process(t_pipex *pipex, char **envp);

//5_parent_process.c
void	parent_process(t_pipex *pipex, char **envp);

//errors.c
void	print_error(char *str);
void	check_file_error(t_pipex *pipex);
void	command_error(t_pipex *pipex, int n);
void	message(char *msg, char *comp);
void	perms_denied(t_pipex *pipex);

//print_error_message.c
void	print_error_msg(t_pipex *pipex);
void	check_error(t_pipex *pipex);

//utils_split.c
char	**ft_split_cmds(char const *s, char c, t_pipex *pipex);

//utils.c
void	free_list(t_pipex *pipex);

#endif