#include "../includes/pipex.h"



int	ft_fork(t_pipex *pipex, char **argv, char *arg, char **env)
{
	int		pipe_fd[2];
	int		pid;
	t_cmd	cmd;
	int	status;

	cmd.cmd_path = NULL;
	cmd.cmd_param = NULL;
	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe");
	pid = fork();
	if (pid == -1)
		ft_error(errno, "Open Fork");
	if (pid == 0)
	{
		//printf("%s\n", arg);
		if(!ft_get_path(env, arg, &cmd))
		{
			printf("aaaaaah\n");
			exit(0);
		}
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			write(STDERR_FILENO, "erro2", 5);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(pipex->infile_fd);
		exec(argv, &cmd, env);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		write(STDERR_FILENO, "erro3", 5);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(pipex->infile_fd);
	waitpid(pid, &status, 0);
	if WIFEXITED(status)
	 	return (WEXITSTATUS(status));
	return (1);
}

int ft_last_cmd(t_pipex *pipex, char **argv, char *arg, char **env)
{
	t_cmd	cmd;
	int	status;
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
	waitpid(pid, &status, 0);
	if WIFEXITED(status)
	 	return (WEXITSTATUS(status));
	return (2);
}