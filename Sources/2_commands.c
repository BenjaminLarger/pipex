/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:52:23 by blarger           #+#    #+#             */
/*   Updated: 2024/02/23 16:15:56 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	read_cmds(t_pipex *pipex, char *cmd1, char *cmd2, char **envp)
{
	pipex->cmd = malloc(sizeof(t_cmd));
	if (!pipex->cmd)
		return (free(pipex->file), free(pipex), print_error(MALLOC_FAIL));
	pipex->cmd->cmd1 = ft_split_cmds(cmd1, ' ', pipex);
	pipex->cmd->cmd2 = ft_split_cmds(cmd2, ' ', pipex);
	pipex->cmd->valid_cmd1 = true;
	pipex->cmd->valid_cmd2 = true;
	get_script_bash_cmds(pipex, envp);
	check_file_error(pipex);
	check_error(pipex);
}

void	get_script_bash_cmds(t_pipex *pipex, char **envp)
{
	int		i;
	char	**splitted_path;
	int		ret_a;
	int		ret_b;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			splitted_path = ft_split(envp[i] + 5, ':');
			ret_b = find_path_env(pipex, splitted_path, pipex->cmd->cmd2[0], 2);
			ret_a = find_path_env(pipex, splitted_path, pipex->cmd->cmd1[0], 1);
			i = -1;
			while (splitted_path[++i])
				free(splitted_path[i]);
			free(splitted_path);
			return ;
		}
		i++;
	}
	if (envp[i] == NULL)
		return (free_list(pipex), print_error(ENV));
}

int	is_executable(const char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	else
		return (0);
}

int	find_path_env(t_pipex *pipex, char **splitted_path, char *cmd, int n)
{
	char	*test;
	char	*path;
	int		i;

	i = 0;
	while (splitted_path[i])
	{
		path = ft_strjoin(splitted_path[i], "/");
		test = ft_strjoin(path, cmd);
		free(path);
		if (is_executable(test) == 1)
		{
			if (n == 1)
				pipex->cmd->bash_path_cmd1 = ft_strdup(test);
			else
				pipex->cmd->bash_path_cmd2 = ft_strdup(test);
			return (free(test), 1);
		}
		free(test);
		i++;
	}
	return (command_error(pipex, n), 0);
}
