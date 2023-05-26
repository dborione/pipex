#include "../includes/pipex.h"

void	exec(t_cmd *cmd, char **argv)
{
	cmd->file = argv[1];
	cmd->ptr = NULL;
	char *arg[] = {cmd->cmd_path, cmd->cmd_param, cmd->file, cmd->ptr};
	if (execve(cmd->cmd_path, arg, NULL) == -1)
        ft_error(0, "cmd execution error");
}

void	ft_open_files(char **argv, int argc, t_pipex *pipex)
{
	int	infile_fd;
	int	outfile_fd;

	infile_fd = open(argv[1], O_CREAT, 0777);
	if (infile_fd == -1)
        ft_error(0, "infile opening error");
	pipex->infile_fd = infile_fd;
	outfile_fd = open(argv[argc - 1], O_CREAT, 0777);
	if (outfile_fd == -1)
        ft_error(0, "infile opening error");
	pipex->outfile_fd = outfile_fd;
}

void	ft_fork(t_pipex *pipex, char **argv, char *arg, char **env)
{
	int		pipe_fd[2];
	int		pid;
	t_cmd	cmd;

	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe Error");
	pid = fork();
	if (pid == -1)
		ft_error(1, "Open Fork Error");
	if (pid == 0)
	{
		ft_get_path(env, arg, &cmd);
    	//printf("%s\n", cmd.cmd_param);
		dup2(pipex->infile_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(pipex->infile_fd);
		exec(&cmd, argv);
	}
	dup2(pipex->outfile_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(pipex->outfile_fd);
	waitpid(pid, NULL, 0);
}









// void ft_fork_cmd1(int *pipe_fd, t_cmd *cmd, char *arg)
// {
// 	int	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		ft_error(1, "Open Fork Error");
// 	if (pid == 0)
// 	{
// 		int file_fd;


// 		// test
// 		//dup2(file_fd, STDOUT_FILENO);

// 		dup2(file_fd, STDIN_FILENO);	
// 		dup2(pipe_fd[1], STDOUT_FILENO);
// 		close(file_fd);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);
// 		//cmd->output = get_next_line(file_fd);
// 		char *exec_arg[] = {cmd->cmd_path, cmd->cmd_param, arg, NULL};
// 		if (execve(cmd->cmd_path, exec_arg, NULL) == -1)
//             ft_error(0, "cmd execution error");
// 	}
// }







// void ft_fork_cmd2(int *pipe_fd, t_cmd *cmd2, char **argv)
// {
// 	int	pid2;
	
// 	pid2 = fork();
// 	if (pid2 == -1)
// 		ft_error(1, "Open Fork Error");
// 	if (pid2 == 0)
// 	{
// 		int file_fd;
		
// 		file_fd = open(argv[4], O_RDWR | O_CREAT, 0777);
//     	if (file_fd == -1)
//         	ft_error(0, "file opening error");

// 		dup2(pipe_fd[0], STDIN_FILENO);
// 		dup2(file_fd, STDOUT_FILENO);
// 		close(file_fd);
// 		close(pipe_fd[0]);
// 		close(pipe_fd[1]);

// 		char *exec_arg[] = {cmd2->cmd_path, cmd2->cmd_param, cmd2->output, NULL};
// 		if (execve(cmd2->cmd_path, exec_arg, NULL) == -1)
//             ft_error(0, "cmd2 execution error");
// 		close(file_fd);
// 	}
// }