/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:18:53 by dborione          #+#    #+#             */
/*   Updated: 2023/06/08 10:55:43 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**ft_get_env(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (pipex->p_data.env[++i])
	{
		if (!ft_strncmp("PATH=", pipex->p_data.env[i], 5))
		{
			pipex->p_data.env_paths = ft_split(&pipex->p_data.env[i][5], ':');
			if (!pipex->p_data.env_paths)
				ft_error(CMD_NOT_FOUND, pipex);
		}
	}
	return (pipex->p_data.env_paths);
}

int	ft_path_as_arg(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->p_data.full_arg[i])
		i++;
	pipex->p_data.exec_arg = malloc(sizeof(pipex->p_data.exec_arg) * (i + 1));
	pipex->p_data.exec_arg[0] = ft_strdup(pipex->p_data.full_arg[0]);
	if (!pipex->p_data.exec_arg[0])
		return (ft_free_all(pipex));
	i = 1;
	while (pipex->p_data.full_arg[i])
	{
		pipex->p_data.exec_arg[i] = ft_strdup(pipex->p_data.full_arg[i]);
		if (!pipex->p_data.exec_arg[i])
			return (ft_free_tab(pipex->p_data.exec_arg));
		i++;
	}
	pipex->p_data.exec_arg[i] = NULL;
	return (1);
}

int	ft_get_exec_arg(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->p_data.full_arg[i])
		i++;
	pipex->p_data.exec_arg = malloc(sizeof(pipex->p_data.exec_arg) * (i + 1));
	pipex->p_data.exec_arg[0] = ft_strdup(pipex->p_data.cmd_full);
	if (!pipex->p_data.exec_arg[0])
		return (ft_free_all(pipex));
	i = 1;
	while (pipex->p_data.full_arg[i])
	{
		pipex->p_data.exec_arg[i] = ft_strdup(pipex->p_data.full_arg[i]);
		if (!pipex->p_data.exec_arg[i])
			return (ft_free_tab(pipex->p_data.exec_arg));
		i++;
	}
	pipex->p_data.exec_arg[i] = NULL;
	return (1);
}

int	ft_get_full_path(t_pipex *pipex)
{
	int		i;
	char	*tmp;

	i = -1;
	while (pipex->p_data.env_paths[++i])
	{
		tmp = ft_strjoin(pipex->p_data.env_paths[i],
				pipex->p_data.cmd_full);
		if (!tmp)
			return (0);
		if (access(tmp, X_OK) == 0)
		{
			pipex->p_data.cmd_full = ft_strdup(tmp);
			if (!pipex->p_data.cmd_full)
				return (0);
			free(tmp);
			return (ft_get_exec_arg(pipex));
		}
		free(tmp);
	}
	return (0);
}

int	ft_get_path(char *arg, t_pipex *pipex)
{
	pipex->p_data.argv = arg;
	pipex->p_data.full_arg = ft_split(arg, ' ');
	if (!pipex->p_data.full_arg)
		return (ft_free_all(pipex));
	if (access(pipex->p_data.full_arg[0], F_OK) == 0)
		return (ft_path_as_arg(pipex));
	pipex->p_data.env_paths = ft_get_env(pipex);
	pipex->p_data.cmd_full = ft_strjoin("/", pipex->p_data.full_arg[0]);
	if (!pipex->p_data.cmd_full)
		return (ft_free_all(pipex));
	if (!ft_get_full_path(pipex))
		return (ft_error(CMD_NOT_FOUND, pipex));
	return (1);
}
