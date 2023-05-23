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

int ft_get_path(char **env, char *argv, t_cmds *cmds)
{
    char **paths;
    char *correct_path;
    int i;

    i = 0;
    correct_path = NULL;
    while (ft_strncmp("PATH=", env[i++], 5))
    {
        paths = ft_split(&env[i][5], ':');
        if (!paths)
        {
            ft_free_tab(paths);
            ft_error(EXIT_FAILURE, "Split Error");
        }
    }
    char **path_with_args = ft_split(argv, ' ');
    cmds->cmd1 = path_with_args[0];
    cmds->cmd1_arg = path_with_args[1];
    //path_with_args[0] = cmd1 ex 'ls'
    //path_with_args[1] = cmd1 args ex '-l'
    correct_path = ft_get_correct_path(path_with_args[0], paths);
    ft_free_tab(paths);
    if (!correct_path)
        ft_error(0, "command not found");
    cmds->cmd1 = correct_path;
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
