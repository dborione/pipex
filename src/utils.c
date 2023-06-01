#include "../includes/pipex.h"

void	exec(char **argv, t_cmd *cmd, char **env)
{
	int	exec;

	char *arg[] = {cmd->cmd_path, cmd->cmd_param, NULL};
	exec = execve(cmd->cmd_path, arg, env);
	if (exec == -1)
        ft_error(errno, "command not found");
}

void	ft_open_files(char **argv, int argc, t_pipex *pipex)
{
	if (pipex->infile_fd == 0)
	{
		if (access(argv[1], R_OK) == -1)
			ft_error(0, "access1");
		pipex->infile_fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0777);
		if (pipex->infile_fd == -1)
			ft_error(errno, "infile open");
	}
	if (access(argv[argc - 1], R_OK) == -1)
		ft_error(errno, "access2");
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (pipex->outfile_fd == -1)
        ft_error(errno, "outfile open");
}

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