#include "../includes/pipex.h"

void ft_fork_cmd1(int *pipe_fd, t_cmd *cmd, char *arg)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error(1, "Open Fork Error");
	if (pid == 0)
	{
		int file_fd;

		file_fd = open(arg, O_RDWR | O_CREAT, 0777);
		if (file_fd == -1)
        	ft_error(0, "file opening error");

		dup2(file_fd, STDOUT_FILENO);
		
		//dup2(pipe_fd[0], STDIN_FILENO);
		close(file_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		char *exec_arg[] = {cmd->cmd, cmd->cmd_param, arg, NULL};
		if (execve(cmd->cmd, exec_arg, NULL) == -1)
            ft_error(0, "cmd execution error");
	}
}

void ft_fork_cmd2(int *pipe_fd, t_cmd *cmd2, char *arg)
{
	int	pid2;
	
	pid2 = fork();
	if (pid2 == -1)
		ft_error(1, "Open Fork Error");
	if (pid2 == 0)
	{
		int file_fd;
		
		file_fd = open(arg, O_RDWR | O_CREAT, 0777);
    	if (file_fd == -1)
        	ft_error(0, "file opening error");

		//dup2(file_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);

		close(pipe_fd[0]);
		close(pipe_fd[1]);

		char *exec_arg[] = {cmd2->cmd, cmd2->cmd_param, arg, NULL};
		if (execve(cmd2->cmd, exec_arg, NULL) == -1)
            ft_error(0, "cmd2 execution error");
		//close(file_fd);
	}
}