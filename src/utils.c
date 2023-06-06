#include "../includes/pipex.h"

int	ft_init_pipex(t_pipex *pipex, char **env)
{
	pipex->p_data.env = env;
	pipex->p_data.env_paths = NULL;
	pipex->p_data.cmd_full = NULL;
	pipex->p_data.cmd_name_and_param = NULL;
	pipex->p_data.exec_arg = NULL;
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->pid1 = 0;
	pipex->pid2 = 0;
	return (1);
}

void	ft_open_files(char **argv, int argc, t_pipex *pipex)
{
	pipex->outfile_fd = open(argv[argc - 1],
			O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (pipex->outfile_fd == -1)
		ft_error(0, "Outfile Opening Error");
	if (pipex->infile_fd == 0)
	{
		if (access(argv[1], R_OK) == -1)
			ft_error(0, "infile open");
		pipex->infile_fd = open(argv[1], O_RDONLY, 0777);
		if (pipex->infile_fd == -1)
			ft_error(0, "infile open");
	}
	// if (access(argv[argc - 1], R_OK) == -1)
	// 	ft_error(0, "access2");
}

void	ft_waitpids(t_pipex *pipex)
{
	int	status;

	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
}

int	ft_free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
	return (0);
}

int	ft_error(int error_code, char *error_message)
{
	perror (error_message);
	//exit(error_code);
    return (0);
}
