#include "../includes/pipex.h"

void ft_close_fds(int pipe_fd_0, int pipe_fd_1, int infile_fd)
{
	close(pipe_fd_0);
	close(pipe_fd_1);
	close(infile_fd);
}

void	exec(char **argv, t_cmd *cmd, char **env)
{
	int		exec;

	exec = execve(cmd->cmd_path, cmd->exec_arg, env);
	if (exec == -1)
        ft_error(CMD_NOT_FOUND, "command not found");
}

int	ft_fork(t_pipex *pipex, char **argv, char *arg, char **env)
{
	t_cmd	cmd;
	int		pipe_fd[2];
	int		status;
	int		pid;

	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe");
	if ((pid = fork()) == -1)
		ft_error(errno, "Open Fork");
	if (pid == 0)
	{
		if(!ft_get_path(env, arg, &cmd))
			ft_error(CMD_NOT_FOUND, __func__);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_error(0, __func__);
		ft_close_fds(pipe_fd[0], pipe_fd[1], pipex->infile_fd);
		exec(argv, &cmd, env);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_error(0, __func__);
	ft_close_fds(pipe_fd[0], pipe_fd[1], pipex->infile_fd);
	waitpid(pid, &status, 0);
	if WIFEXITED(status)
	 	return (WEXITSTATUS(status));
	return (1);
}

int ft_last_cmd(t_pipex *pipex, char **argv, char *arg, char **env)
{
	t_cmd	cmd;
	int		status;
	int		pid;
	
	pid = fork();
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