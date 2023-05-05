#include "../includes/pipex.h"
#include "../libft/includes/libft.h"
#include "../get_next_line/get_next_line.h"

int ft_error(int error_code, char *error_message)
{
    perror(error_message);
    return (error_code);
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

char *ft_get_path(char **env, char *argv)
{
    char **paths;
    char *correct_path;
    int i;

    i = 0;
    correct_path = NULL;
    while (ft_strncmp("PATH=", env[i++], 5))
    {
        paths = ft_split(&env[i][5], ':'); //leak here
        if (!paths)
        {
            ft_free_tab(paths);
            ft_error(0, "Split Error");
            exit(0);
        }
    }
    correct_path = ft_get_correct_path(correct_path, paths, argv);
    ft_free_tab(paths);
    return (correct_path);
}

char *ft_get_correct_path(char *correct_path, char **paths, char *argv)
{
    int i;
    char *argv_path;

    i = 0;
    argv_path = ft_strjoin("/", argv); 
    while (paths[i])
    {
        correct_path = ft_strjoin(paths[i], argv_path); //leak here
        if (!correct_path)
        {
            free(argv_path);
            ft_free_tab(paths);
            exit(0);
        }
        if (access(correct_path, F_OK) == 0)
        {
            free(argv_path);           
            return (correct_path);
        }
        i++;
    }
    free(argv_path);
    ft_free_tab(paths);
    exit(0);
}
