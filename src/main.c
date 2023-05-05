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

	char *path;
	if (argc != 5)
		return (ft_error(1, "Wrong Number of arguments"));
	path = ft_get_path(env, argv[2]);
	printf("%s\n", path);



    // int pipe_fd[2];
    // if (pipe(pipe_fd) == -1)
	// 	return (ft_error(1, "Open Pipe Error"));

    // int pid = fork();
    // if (pid == -1)
    //     return (ft_error(1, "Open Fork Error"));

    // if (pid == 0) //Child
    // {
    //     int exec = execve("/usr/bin/", arg, NULL);
    //     if (exec == -1)
    //         return (ft_error(1, "cmd execution error"));





























       // while((dup2(pipe_fd[1], STDOUT_FILENO) == -1)); //Send output to write end of pipe
	// 	close(pipe_fd[1]);
    // }
    // close(pipe_fd[1]);
	



	// 	// execve(file, args, env);
	// 	// while((dup2(pipe_fd[1], STDOUT_FILENO) == -1));
	// 	// close(pipe_fd[0]);
	// 	// close(pipe_fd[1]);
	// }

	// int id2 = fork();
	// if (id2 == -1)
	// 	return (1);
	// if (id2 == 0){
	// 	execve(file, args, env);
	// 	while((dup2(pipe_fd[0], STDIN_FILENO) == -1));
	// 	close(pipe_fd[0]);
	// 	close(pipe_fd[1]);
	// }
	// close(pipe_fd[0]);
	// close(pipe_fd[1]);
	// wait(NULL);// -> wait for child processes to finish;

	

//	char *file = "/usr/bin/whereis";
//	char *args[] = {"/usr/bin/whereis", $ENV, NULL};
//	char *env[] = {"ENV=fjdjs", NULL};

	exit(0);
}
