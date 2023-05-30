#include "../includes/pipex.h"

int ft_error(int error_code, char *error_message)
{
    perror(error_message);
    //printf("%d", error_code);
    exit(error_code);
}

void ft_free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
        free(tab[x++]);
    free(tab);
}

int ft_get_path(char **env, char *argv, t_cmd *cmd)
{
    char	**paths;
    int     i;

    i = -1;
    while (env[++i])
    {
        if (!ft_strncmp("PATH=", env[i], 5))
        {
            paths = ft_split(&env[i][5], ':');
            if (!paths)
            {
                ft_free_tab(paths);
                return (-1);
            }
        }
    }
    ft_free_tab(paths);
    return (1);
}