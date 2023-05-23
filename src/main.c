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
#include <sys/types.h>
#include <sys/wait.h>

//pipex file1 cmd1 cmd2 file2
//int execve(const char *pathname, char *const argv[], char *const envp[]);
//fd = open(argv[1], O_RDWR);
//write(fd, "1", 1)
// fd[0] - read
// fd[1] - write

int	main(int argc, char **argv, char **env) {

	t_cmd	cmd1;
	t_cmd	cmd2;
	// 	ft_error(EXIT_FAILURE, "Wrong Number of arguments");
	ft_get_path(env, argv[2], &cmd1);
	ft_get_path(env, argv[3], &cmd2);
	// printf("%s\n", cmd1.cmd);
	// printf("%s\n", cmd1.cmd_arg);
	// printf("%s\n", cmd2.cmd);
	// printf("%s\n", cmd2.cmd_arg);

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe Error");

	// int pid1;
	// ft_fork(pipe_fd, pid1, 1, 0, STDOUT_FILENO, &cmd1, argv[1]);


    int pid1 = fork();
    if (pid1 == -1)
        ft_error(EXIT_FAILURE, "Open Fork1 Error");
    if (pid1 == 0) //Child
    {
		while((dup2(pipe_fd[1], STDOUT_FILENO) == -1)); //Send output to write end of pipe
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		char *arg1[] = {cmd1.cmd, cmd1.cmd_arg, argv[1], NULL};
    	int exec = execve(cmd1.cmd, arg1, NULL);
        if (exec == -1)
            ft_error(0, "cmd1 execution error");	
    }
	
	int pid2 = fork();
	if (pid2 == -1)
		ft_error(1, "Open Fork2 Error");
	if (pid2 == 0)
	{
		while((dup2(pipe_fd[0], STDIN_FILENO) == -1));
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		char *arg2[] = {cmd2.cmd, cmd2.cmd_arg, argv[5], NULL};
		int exec2 = execve(cmd2.cmd, arg2, NULL);
        if (exec2 == -1)
            ft_error(0, "cmd2 execution error");
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);




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
