#include "../includes/pipex.h"

int ft_free_tabs(char **tab1, char **tab2)
{
    if (tab1)
        ft_free_tab(tab1);
    if (tab2)
        ft_free_tab(tab2);
    return (0);
}

int ft_free_str(char *s1, char *s2)
{
    if (s1)
        free(s1);
    if (s2)
        free(s2);
    return (0);
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
                return(NULL);
        }
    }
    return(paths);
}

int ft_get_full_path(char **cmd_full, char **paths, t_cmd *cmd)
{
    char    *full_path;
    char    *cmd_path_clone;
    int     i;

    full_path = NULL;
    cmd_path_clone = NULL;
    i = -1;
    while (paths[++i])
    {
        full_path = ft_strjoin(paths[i], "/");
        if (!full_path)
            return(ft_free_str(full_path, cmd_path_clone)); //free all;
        cmd_path_clone = ft_strjoin(full_path, cmd_full[0]);
        if (!cmd_path_clone)
            return(ft_free_str(full_path, cmd_path_clone)); //free(all)
        if (access(cmd_path_clone, F_OK) == 0)
        {
            cmd->cmd_path = ft_strdup(cmd_path_clone);
            //if (!cmd->cmd_path)
            ft_free_str(full_path, cmd_path_clone);
            return(1);
        }
        else
             return(ft_free_str(full_path, cmd_path_clone));
        ft_free_str(full_path, cmd_path_clone);
    }
    ft_free_str(full_path, cmd_path_clone);
    return (0);
}

int ft_get_path(char **env, char *arg, t_cmd *cmd)
{
    char	**paths;
    char    **cmd_full;

    paths = NULL;
    cmd_full = NULL;
    paths = ft_get_env(env, paths);
    if (!paths)
        return (0);
    cmd_full = ft_split(arg, ' ');
    if (!cmd_full)
        return (ft_free_tab(paths));
    if (!ft_get_full_path(cmd_full, paths, cmd))
        return (ft_free_tabs(paths, cmd_full));

    if (cmd_full[1])
        cmd->cmd_param = ft_strdup(cmd_full[1]);
         //if (!cmd->cmd_param)

    ft_free_tabs(paths, cmd_full);
    return (1);
}