
#include "../includes/pipex.h"

void	ft_exec(t_pipex *pipex)
{
	int		exec;

	exec = execve(pipex->p_data.exec_arg[0], pipex->p_data.exec_arg, pipex->p_data.env);
	if (exec == -1)
		ft_error(CMD_NOT_FOUND, "Command not found");
}

void    ft_dup2(int fd1, int fd2)
{
  if (dup2(fd1, fd2) == -1)
    ft_error(0, "Error Duplicating Stdin");
}

void ft_cmd1(t_pipex *pipex, char *argv)
{
    int pipe_fd[2];
    int pid;

    if (pipe(pipe_fd) == -1)
		  ft_error(0, "Error Opening Pipe");
    pid = fork();
    if (pid == -1)
		  ft_error(0, "Error Creating Fork");
    if (pid == 0)
    {
      ft_get_path(argv, pipex);
      ft_dup2(pipex->infile_fd, STDIN_FILENO);
      close(pipex->infile_fd);
	    ft_dup2(pipe_fd[1], STDOUT_FILENO);
	    close(pipe_fd[1]);
	    ft_exec(pipex);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
}

void ft_cmd2(t_pipex *pipex, char *argv)
{
    int pipe_fd[2];
    int pid;

    if (pipe(pipe_fd) == -1)
		ft_error(0, "Error Opening Pipe");
    pid = fork();
    if (pid == -1)
		ft_error(0, "Error Creating Fork");
    if (pid == 0)
    {
      ft_get_path(argv, pipex);
      ft_dup2(pipe_fd[0], STDIN_FILENO);
      close(pipe_fd[0]);
	    ft_dup2(pipex->outfile_fd, STDOUT_FILENO);
	    close(pipex->outfile_fd);
	    ft_exec(pipex);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
}