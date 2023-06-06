
#include "../includes/pipex.h"


int	ft_free_all(t_pipex *pipex)
{
	if (pipex->p_data.env_paths)
		ft_free_tab(pipex->p_data.env_paths);
	// if (pipex->p_data.cmd_full)
	// 	ft_free_tab(pipex->p_data.cmd_full);
	// if (pipex->p_data.cmd_path_clone)
	// 	free(pipex->p_data.cmd_path_clone);
	return (0);
}

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
				ft_error(0, "env path split");
		}
	}
	return (pipex->p_data.env_paths);
}

int	ft_get_exec_arg(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->p_data.cmd_name_and_param[i])
		i++;
	pipex->p_data.exec_arg = malloc(sizeof(pipex->p_data.exec_arg) * ( i + 1));
	pipex->p_data.exec_arg[0] = strdup(pipex->p_data.cmd_full);
	i = 1;
	while (pipex->p_data.cmd_name_and_param[i])
	{
		pipex->p_data.exec_arg[i] = strdup(pipex->p_data.cmd_name_and_param[i]);
		if (!pipex->p_data.exec_arg[i])
			return (ft_free_tab(pipex->p_data.exec_arg));
		i++;
	}
	pipex->p_data.exec_arg[i] = NULL;
	return (1);
}

int	ft_get_full_path(t_pipex *pipex)
{
	int	i;
	char	*tmp;

	i = -1;
	while (pipex->p_data.env_paths[++i])
	{
		tmp = ft_strjoin(pipex->p_data.env_paths[i],
				pipex->p_data.cmd_full);
		if (!tmp)
			return (0);
		if (access(tmp, F_OK) == 0)
		{
			pipex->p_data.cmd_full = ft_strdup(tmp);
			if (!pipex->p_data.cmd_full)
				return (0);
			free(tmp);
			ft_get_exec_arg(pipex);
		 	return (1);
		};
		free(tmp);
	}
	//ft_free_tab(pipex->p_data.env_paths);
	//ft_free_tab(pipex->p_data.cmd_full);
	return (2);
}

int	ft_get_path(char *arg, t_pipex *pipex)
{
    pipex->p_data.env_paths = ft_get_env(pipex);

    pipex->p_data.cmd_name_and_param = ft_split(arg, ' ');
    if (!pipex->p_data.cmd_name_and_param)
		return (ft_free_all(pipex));

    pipex->p_data.cmd_full = ft_strjoin("/", pipex->p_data.cmd_name_and_param[0]);
	if (!pipex->p_data.cmd_full)
		return (ft_free_all(pipex));
	if (!ft_get_full_path(pipex))
		return (ft_free_all(pipex));
	else if (ft_get_full_path(pipex) == 2)
		return (0);
    return (1);
}