#include "../includes/pipex.h"

void ft_free_path_tabs(char **tab1, char **tab2, int error)
{
    if (tab1)
        ft_free_tab(tab1);
    if (tab2)
        ft_free_tab(tab2);
    if (error == EXIT_FAILURE)
        ft_error(EXIT_FAILURE, "Split2 Error");
    if (error == 0)
        ft_error(EXIT_FAILURE, "command not found");
}

char **ft_get_env(char **env, char **paths)
{
    int i;

    i = -1;
    while (env[++i])
    {
        if (!ft_strncmp("PATH=", env[i], 5))
        {
            paths = ft_split(&env[i][5], ':');
            if (!paths)
                return(ft_free_tab(paths));
        }
    }
    return (paths);
}

int ft_get_full_path(char **cmd_full, char **paths, t_cmd *cmd)
{
    char    *full_path;
    char    *cmd_path_clone;
    int     i;

    i = -1;
    while (paths[++i])
    {
        full_path = ft_strjoin(paths[i], "/");
        //if (!full_path)
            //free all
        cmd_path_clone = ft_strjoin(full_path, cmd_full[0]);
        // if (!cmd->cmd_path)
        //      free(all)
        if (access(cmd_path_clone, F_OK) == 0)
        {
            cmd->cmd_path = ft_strdup(cmd_path_clone);
            free(cmd_path_clone);
            free(full_path);
            return (1);
        }
        free(full_path);
        free(cmd_path_clone);
    }
    free(full_path);
    free(cmd_path_clone);
    return (0);
}

int ft_get_path(char **env, char *arg, t_cmd *cmd)
{
    char	**paths;
    char    **cmd_full;

    paths = NULL;
    paths = ft_get_env(env, paths);
    cmd_full = ft_split(arg, ' ');
    if (!cmd_full)
        return(ft_free_tab(paths));

    ft_get_full_path(cmd_full, paths, cmd);
    if (cmd_full[1])
        cmd->cmd_param = ft_strdup(cmd_full[1]);
    else
        cmd->cmd_param = NULL;
    ft_free_tab(cmd_full);
    ft_free_tab(paths);
    return (1);
}