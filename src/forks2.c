#include "../includes/pipex.h"

void    ft_dup2(int fd1, int fd2)
{
    if (dup2(fd1, fd2) == -1)
		ft_error(0, "Error Duplicating Stdin");
}

void ft_close_pipe_fd(int **pipe_fd)
{
    int i = -1;
    int j = -1;

    while (pipe_fd[++i])
    {
        while (pipe_fd[i][j])
        {
            if (i == 0 && j == 0)
                j++;
            if (i == 1 && j == 1)
                j++;
            close(pipe_fd[i][j]);
        }
    }
}

int ft_fork()
{
    int i;
    int **pipe_fd;

    i = argc - 2;
    pipe_fd = malloc(sizeof(*pipe_fd) * i);
    if (!pipe_fd)
        return 2;
    while (pipe_fd[i])
    {
        if (pipe(pipe_fd[i]) == -1)
            return 3;
    }


    int pid;
    pid = fork();
    if (pid == 0)
    {
        ft_close_pipe_fd(&pipe_fd); // -> only need pipe_fd[0][0] and pipe_fd[1][1] open for first child
        ft_dup2(pipex->infile_fd, STDIN_FILENO);
	    close(pipex->infile_fd);
	    ft_dup2(pipe_fd[i][1], STDOUT_FILENO);
	    close(pipe_fd[i][1]);
	    ft_exec();
    }


}