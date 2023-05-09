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

	char *path_cmd1;
	char *path_cmd2;
	if (argc != 5)
		ft_error(EXIT_FAILURE, "Wrong Number of arguments");
	path_cmd1 = ft_get_path(env, argv[2]);
	path_cmd2 = ft_get_path(env, argv[3]);
	// printf("%s\n", path_cmd1);
	// printf("%s\n", path_cmd2);

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe Error");

    int pid = fork();
    if (pid == -1)
        ft_error(EXIT_FAILURE, "Open Fork Error");

    if (pid == 0) //Child
    {
		char *arg1[] = {argv[2], argv[1], NULL};
        int exec = execve(path_cmd1, arg1, NULL);
        if (exec == -1)
            ft_error(0, "cmd1 execution error");
       	while((dup2(pipe_fd[1], STDOUT_FILENO) == -1)); //Send output to write end of pipe
		close(pipe_fd[1]);
    }
    close(pipe_fd[1]);
	

	int pid2 = fork();
	if (pid2 == -1)
		ft_error(1, "Open Fork Error");
	if (pid2 == 0)
	{
		char *arg2[] = {argv[4], argv[5], NULL};
		int exec2 = execve(path_cmd2, arg2, NULL);
        if (exec2 == -1)
            ft_error(0, "cmd2 execution error");
		while((dup2(pipe_fd[0], STDIN_FILENO) == -1));
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(path_cmd1);
	free(path_cmd2);

	int child_status2;
	int child_status1;
	int	wstatus;
	child_status1 = waitpid(pid, &wstatus, 0);
	child_status2 = waitpid(pid2, NULL, 0);
	// if (WIFEXITED(wstatus)) //check if program terminated properly 
	// 	child_status2 = WEXITSTATUS(wstatus);
	//printf("%d\n", child_status1);
	//printf("%d\n", child_status2);
	exit(child_status2);

	//return (0);
}
