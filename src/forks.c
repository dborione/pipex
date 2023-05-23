#include "../includes/pipex.h"
#include <sys/types.h>
#include <sys/wait.h>

void ft_fork(int pipe_fd, int pid, int pipe_write, int pipe_read, int STD, t_cmd *cmd, char **arg)
{
	pid = fork();
	if (pid == -1)
		ft_error(1, "Open Fork2 Error");
	if (pid == 0)
	{
		while((dup2(pipe_fd[pipe_write], STD) == -1));
		close(pipe_fd[pipe_read]);
		close(pipe_fd[pipe_write]);
		char *arg2[] = {cmd.cmd, cmd.cmd_arg, argv[5], NULL};
		int exec = execve(cmd.cmd, arg2, NULL);
        if (exec == -1)
            ft_error(0, "cmd2 execution error");
	}
}