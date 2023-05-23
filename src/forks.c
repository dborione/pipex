#include "../includes/pipex.h"

void ft_fork(int *pipe_fd, int pid, int pipe_write_or_read, int STD, t_cmd *cmd, char *arg)
{
	pid = fork();
	if (pid == -1)
		ft_error(1, "Open Fork Error");
	if (pid == 0)
	{
		dup2(pipe_fd[pipe_write_or_read], STD);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		char *arg2[] = {cmd->cmd, cmd->cmd_param, arg, NULL};
		int exec = execve(cmd->cmd, arg2, NULL);
        if (exec == -1)
            ft_error(0, "cmd execution error");
	}
}