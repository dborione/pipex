#include "../includes/pipex.h"
#include "../libft/includes/libft.h"

int ft_error(int error_code, char *error_message)
{
    perror(error_message);
    //printf("%d", error_code);
    exit(error_code);
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

int ft_get_path(char **env, char *arg, t_cmd *cmd)
{
    char	**paths;
    char    **cmd_full;
    char    *full_path;
    int 	i;

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
    cmd_full = ft_split(arg, ' ');
    if (!cmd_full)
        return(ft_free_tab(paths));
    i = -1;
    while (paths[++i])
    {
        full_path = ft_strjoin(paths[i], "/");
        //if (!full_path)
            //free all
        cmd->cmd_path = ft_strjoin(full_path, cmd_full[0]);
        // if (!cmd->cmd_path)
        //      free(all)
        if (access(cmd->cmd_path, F_OK) == 0)
            break ;
        free(full_path);
        free(cmd->cmd_path);
    }
    // printf("%s\n", cmd->cmd_path);
//    free(full_path);
  //  free(cmd->cmd_path);

    if (cmd_full[1])
        cmd->cmd_param = cmd_full[1];
    else
        cmd->cmd_param = NULL;
   // ft_free_tab(cmd_full);
    ft_free_tab(paths);
    return (1);
}

char *ft_get_correct_path(char *correct_path, char **paths)
{
    int		i;
    char	*argv_path;

    i = 0;
    argv_path = ft_strjoin_gnl("/", correct_path); 
    if (!argv_path)
        ft_error(0, "strjoin1");
    while (paths[i])
    {
        correct_path = ft_strjoin_gnl(paths[i], argv_path); //leak here
        if (!correct_path)
        {
            free(argv_path);
            ft_free_tab(paths);
            ft_error(0, "strjoin2");
        }
        if (access(correct_path, F_OK) == 0)
        {
            free(argv_path);           
            return(correct_path);
        }
        i++;
    }
    free(argv_path);
    ft_free_tab(paths);
    //ft_error(0, "path not found");
    return (NULL);
}
