/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:45:02 by dborione          #+#    #+#             */
/*   Updated: 2023/05/03 13:15:39 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//pipex file1 cmd1 cmd2 file2
//int execve(const char *pathname, char *const argv[], char *const envp[]);
//fd = open(argv[1], O_RDWR);
// fd[0] - read
// fd[1] - write

int	main(int argc, char **argv, char **env) {

	t_cmd	cmd1;
	t_cmd	cmd2;
	int	pid1;
	int	pid2;
	// 	ft_error(EXIT_FAILURE, "Wrong Number of arguments");
	ft_get_path(env, argv[2], &cmd1);
	ft_get_path(env, argv[3], &cmd2);

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe Error");

	pid1 = 0;
	ft_fork(pipe_fd, pid1, 1, STDOUT_FILENO, &cmd1, argv[1]);
	pid2 = 0;
	
	//printf("fdfds\n");
	//ft_fork(pipe_fd, pid2, file_fd, 1, &cmd2, argv[5]);

	pid2 = fork();
	if (pid2 == -1)
		ft_error(1, "Open Fork Error");
	if (pid2 == 0)
	{
		int file_fd = open(argv[4], O_RDWR | O_CREAT, 0777);
    	if (file_fd == -1)
        	ft_error(0, "file opening error");
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(file_fd, STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		char *arg2[] = {cmd2.cmd, cmd2.cmd_param, argv[4], NULL};
		int exec = execve(cmd2.cmd, arg2, NULL);
        if (exec == -1)
            ft_error(0, "cmd2 execution error");
		//close(file_fd);
	}












	//printf("ffdsfdsfdsfdsfd\n");
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	//printf("nnbvnbv\n");



	// free(cmd1.cmd);
	// free(cmd1.cmd_arg);
	// free(cmd2.cmd);
	// free(cmd2.cmd_arg);

	// int child_status2;
	// int child_status1;
	// int	wstatus;
	// child_status1 = waitpid(pid, &wstatus, 0);
	// child_status2 = waitpid(pid2, NULL, 0);
	// if (WIFEXITED(wstatus)) //check if program terminated properly 
	// 	child_status2 = WEXITSTATUS(wstatus);
	//printf("%d\n", child_status1);
	//printf("%d\n", child_status2);
	//exit(child_status2);

	//return (0);
}
