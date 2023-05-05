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

char **ft_get_cmd(char **env)
{
    char **cmd;
    int i;

    i = 0;
    while (!ft_strncmp(env[i++], "PATH", 4))
    {
        cmd = ft_split(&env[i][5], ':');
        if (!cmd)
        {
            ft_free_tab(cmd);
            ft_error(0, "Split Error");
            exit (0);
        }
    }
    return (cmd);
}
