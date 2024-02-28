/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:07:37 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 11:19:20 by blarger          ###   ########.fr       */
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
# include "../Library/get_next_line/get_next_line.h"
# define MAX_PATH_LEN 1024

//1_file_handling.c
void	open_file(t_pipex *pipex, char **argv, int argc);
void	open_here_files(t_pipex *pipex, char **argv);
void	read_from_input(t_pipex *pipex, char **argv);

//2_cmommands.c
void	read_cmds(t_pipex *pipex, int argc, char **argv, char **envp);
void	get_script_bash_cmds(t_pipex *pipex, char **envp, int index);
void	find_path_env(t_pipex *pipex, char **splitted_path, char *cmd, int idx);

//4_child_process.c
void	child_process(t_pipex *pipex, char **envp, int index);

//5_parent_process.c
void	parent_process(t_pipex *pipex, char **envp, int argc);

//6_middle_command.c
void	execute_command(t_pipex *pipex, int index, char **envp);
void	parent_process_manag(t_pipex *pipex, int mid_pipefd[2], pid_t mid_pid);

//errors.c
void	print_error(char *str);
void	check_file_error(t_pipex *pipex);
void	message(char *msg, char *comp, bool *error);

//print_error_message.c
void	print_error_msg(t_pipex *pipex);

//utils_split.c
char	**ft_split_cmds(char const *s, char c, t_pipex *pipex, int index);

//utils.c
void	free_list(t_pipex *pipex);

#endif