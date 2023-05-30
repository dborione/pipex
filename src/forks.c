#include "../includes/pipex.h"

void	exec(char **argv, t_cmd *cmd, char **env)
{
	char *arg[] = {cmd->cmd_path, cmd->cmd_param, NULL};
	if (execve(cmd->cmd_path, arg, env) == -1)
        ft_error(errno, "command not found");
}

void	ft_open_files(char **argv, int argc, t_pipex *pipex)
{
	if (access(argv[1], R_OK) == -1)
		ft_error(0, "access");
	if (access(argv[argc - 1], R_OK) == -1)
		ft_error(0, "access");
	pipex->infile_fd = open(argv[1], O_RDWR | O_CREAT, 0777);
	if (pipex->infile_fd == -1)
        ft_error(errno, "infile open");
	pipex->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0777);
	if (pipex->outfile_fd == -1)
        ft_error(errno, "outfile open");
}

int	ft_fork(t_pipex *pipex, char **argv, char *arg, char **env)
{
	int		pipe_fd[2];
	int		pid;
	t_cmd	cmd;

	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe");
	pid = fork();
	if (pid == -1)
		ft_error(errno, "Open Fork");
	if (pid == 0)
	{
		ft_get_path(env, arg, &cmd);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			write(STDERR_FILENO, "error", 5);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec(argv, &cmd, env);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		write(STDERR_FILENO, "error", 5);
	wait(NULL);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (1);
}

void ft_last_cmd(t_pipex *pipex, char **argv, char *arg, char **env)
{
	t_cmd	cmd;

	int pid = fork();
	if (!pid)
	{
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
			ft_error(0, "dup2");
		close(pipex->outfile_fd);
		if (ft_get_path(env, arg, &cmd) == -1)
			exit(0);
		exec(argv, &cmd, env);
	}
	wait(NULL);
}