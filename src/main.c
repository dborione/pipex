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

//int execve(const char *pathname, char *const argv[], char *const envp[]);
//fd = open(argv[1], O_RDWR);
//write(fd, "1", 1)
// fd[0] - read
// fd[1] - write

	// char *file = "/bin/echo";
	// char *args2 = strcat(argv[1], " child process");
	// char *args[] = {"/bin/echo", args2, NULL};
	// char *env[] = {NULL};

int	main(int argc, char **argv, char **env) {

	char *path_cmd1;
	char *path_cmd2;
	if (argc != 5)
		return (ft_error(1, "Wrong Number of arguments"));
	path_cmd1 = ft_get_path(env, argv[2]);
	path_cmd2 = ft_get_path(env, argv[3]);

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
		return (ft_error(1, "Open Pipe Error"));

    int pid = fork();
    if (pid == -1)
        return (ft_error(1, "Open Fork Error"));

    if (pid == 0) //Child
    {
        int exec = execve(path_cmd1, &argv[1], NULL);
        if (exec == -1)
            return (ft_error(1, "cmd1 execution error"));
       	while((dup2(pipe_fd[1], STDOUT_FILENO) == -1)); //Send output to write end of pipe
		close(pipe_fd[1]);
    }
    close(pipe_fd[1]);
	

	int pid2 = fork();
	if (pid2 == -1)
		return (ft_error(1, "Open Fork Error"));
	if (pid2 == 0){
		int exec2 = execve(path_cmd2, &argv[4], NULL);
        if (exec2 == -1)
            return (ft_error(1, "cmd2 execution error"));
		while((dup2(pipe_fd[0], STDIN_FILENO) == -1));
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(path_cmd1);
	free(path_cmd2);
	wait(NULL);// -> wait for child processes to finish;
	exit(0);
}
