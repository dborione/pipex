#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include "../get_next_line/get_next_line.h"

int ft_error(int error_code, char *error_message)
{
    perror(error_message);
    //printf("%d", error_code);
    exit(error_code);
}

char	**ft_free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
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

int ft_get_path(char **env, char *argv, t_cmd *cmd)
{
    char **paths;
    int i;

    i = 0;
    while (ft_strncmp("PATH=", env[i++], 5))
    {
        paths = ft_split(&env[i][5], ':');
        if (!paths)
        {
            ft_free_tab(paths);
            ft_error(EXIT_FAILURE, "Split1 Error");
        }
    }
    char **path_with_param = ft_split(argv, ' ');
    if (!path_with_param )
        ft_free_path_tabs(paths, path_with_param, EXIT_FAILURE);
    cmd->cmd = path_with_param[0];
    if (path_with_param[1])
        cmd->cmd_param = path_with_param[1];
    cmd->cmd = ft_get_correct_path(path_with_param[0], paths);
    ft_free_tab(paths);
   // ft_free_tab(path_with_args);
    return (1);
}

char *ft_get_correct_path(char *correct_path, char **paths)
{
    int i;
    char *argv_path;

    i = 0;
    argv_path = ft_strjoin("/", correct_path); 
    if (!argv_path)
        ft_error(0, "strjoin1");
    while (paths[i])
    {
        correct_path = ft_strjoin(paths[i], argv_path); //leak here
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
    ft_error(0, "path not found");
}
