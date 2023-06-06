/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:23:49 by dborione          #+#    #+#             */
/*   Updated: 2023/06/05 15:32:06 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_free_all(t_parsing_data *data)
{
	if (data->env_paths)
		ft_free_tab(data->env_paths);
	if (data->cmd_full)
		ft_free_tab(data->cmd_full);
	if (data->cmd_path_clone)
		free(data->cmd_path_clone);
	return (0);
}

char	**ft_get_env(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->env[++i])
	{
		if (!ft_strncmp("PATH=", pipex->env[i], 5))
		{
			pipex->data.env_paths = ft_split(&pipex->env[i][5], ':');
			if (!pipex->data.env_paths)
				ft_error(0, "env path split");
		}
	}
	return (pipex->data.env_paths);
}

int	ft_get_full_path(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->data.env_paths[++i])
	{
		pipex->data.cmd_path_clone = ft_strjoin(pipex->data.env_paths[i],
				pipex->data.cmd_full[0]);
		if (!pipex->data.cmd_path_clone)
			return (0);
		if (access(pipex->data.cmd_path_clone, F_OK) == 0)
		{
			cmd->cmd_path = ft_strdup(data->cmd_path_clone);
			if (!cmd->cmd_path)
				return (0);
			return (1);
		}
		free(data->cmd_path_clone);
	}
	ft_free_tab(data->env_paths);
	ft_free_tab(data->cmd_full);
	return (2);
}

int	ft_get_cmd_full_arg(t_cmd *cmd, t_parsing_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_full[i])
		i++;
	cmd->exec_arg = malloc(sizeof(cmd->exec_arg) * i);
	cmd->exec_arg[0] = strdup(cmd->cmd_path);
	i = -1;
	while (data->cmd_full[++i])
	{
		cmd->exec_arg[i] = strdup(data->cmd_full[i]);
		if (!cmd->exec_arg[i])
			return (ft_free_tab(cmd->exec_arg));
	}
	cmd->exec_arg[i] = NULL;
	return (1);
}

int	ft_get_path(char *arg, t_pipex *pipex)
{
	pipex->data.env_paths = ft_get_env(pipex);
	if (!pipex->data.env_paths)
		return (ft_free_all(&data));
	pipex->data.cmd_full = ft_split(arg, ' ');
	if (!pipex->data.cmd_full)
		return (ft_free_all(&data));
	pipex->data.cmd_full[0] = ft_strjoin("/", pipex->data.cmd_full[0]);
	if (!pipex->data.cmd_full[0])
		return (ft_free_all(&data));
	if (!ft_get_full_path(pipex))
		return (ft_free_all(&data));
	else if (ft_get_full_path(pipex) == 2)
		return (0);
	ft_get_cmd_full_arg(cmd, &data);
	ft_free_all(&data);
	return (1);
}
