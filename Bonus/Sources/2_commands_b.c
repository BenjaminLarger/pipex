/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_commands_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:52:23 by blarger           #+#    #+#             */
/*   Updated: 2024/02/26 11:11:27 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/pipex.h"

void	read_cmds(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int	i;

	pipex->cmds = (t_cmd *)malloc((argc - 2) * sizeof(t_cmd));
	if (!pipex->cmds)
		return (free_list(pipex), print_error(MALLOC_FAIL));
	i = 0;
	while (i < argc - 3)
	{
		pipex->cmds[i].cmd = ft_split_cmds(argv[i + 2], ' ', pipex, i);
		pipex->cmds[i].valid_cmd = true;
		get_script_bash_cmds(pipex, envp, i);
		i++;
	}
	pipex->cmds[i].cmd = NULL;
	pipex->total_cmd = argc - 3;
}

void	get_script_bash_cmds(t_pipex *pipex, char **envp, int idx)
{
	int		i;
	char	**splitted_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			splitted_path = ft_split(envp[i] + 5, ':');
			find_path_env(pipex, splitted_path, pipex->cmds[idx].cmd[0], idx);
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

void	find_path_env(t_pipex *pipex, char **splitted_path, char *cmd, int idx)
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
			pipex->cmds[idx].bash_path = ft_strdup(test);
			return (free(test));
		}
		free(test);
		i++;
	}
	pipex->cmds[idx].valid_cmd = false;
}
