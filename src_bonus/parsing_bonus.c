#include "../includes/pipex.h"

void    ft_data_init(t_parsing_data *data, t_cmd *cmd)
{
    data->env_paths = NULL;
    data->cmd_full = NULL;
    data->cmd_path_clone = NULL;
    cmd->cmd_path = NULL;
}

int ft_free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
	return (0);
}

int    ft_free_all(t_parsing_data *data)
{
    if (data->env_paths)
        ft_free_tab(data->env_paths);
    if (data->cmd_full)
        ft_free_tab(data->cmd_full);
    if (data->cmd_path_clone)
        free(data->cmd_path_clone);
    return (0);
}

char **ft_get_env(char **env, t_parsing_data *data)
{
    int i;

    i = -1;
    while (env[++i])
    {
        if (!ft_strncmp("PATH=", env[i], 5))
        {
            data->env_paths = ft_split(&env[i][5], ':');
            if (!data->env_paths)
                ft_error(0, "env path split");
        }
    }
    return(data->env_paths);
}

int ft_get_full_path(t_parsing_data *data, t_cmd *cmd)
{
    int     i;

    i = -1;
    while (data->env_paths[++i])
    {
        data->cmd_path_clone = ft_strjoin(data->env_paths[i], data->cmd_full[0]);
        if (!data->cmd_path_clone)
            return(0);
        if (access(data->cmd_path_clone, F_OK) == 0)
        {
            cmd->cmd_path = ft_strdup(data->cmd_path_clone);
            if (!cmd->cmd_path)
                return(0);
            return(1);
        }
        free(data->cmd_path_clone);
    }
    ft_free_tab(data->env_paths);
    ft_free_tab(data->cmd_full);
    return(2);
}

int ft_get_cmd_full_arg(t_cmd *cmd, t_parsing_data *data)
{
    int i;
    
    i = 0;
    while (data->cmd_full[++i]);
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

int ft_get_path(char **env, char *arg, t_cmd *cmd)
{
    t_parsing_data data;

    ft_data_init(&data, cmd);
    data.env_paths = ft_get_env(env, &data);
    if (!data.env_paths)
        return(ft_free_all(&data));
    data.cmd_full = ft_split(arg, ' ');
    if (!data.cmd_full)
        return(ft_free_all(&data));
    data.cmd_full[0] = ft_strjoin("/", data.cmd_full[0]);
    if (!data.cmd_full[0])
        return(ft_free_all(&data));
    if (!ft_get_full_path(&data, cmd))
        return(ft_free_all(&data));
    else if (ft_get_full_path(&data, cmd) == 2)
        return (0);
    ft_get_cmd_full_arg(cmd, &data);
    ft_free_all(&data);
    return (1);
}