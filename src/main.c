/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:45:02 by dborione          #+#    #+#             */
/*   Updated: 2023/05/03 12:44:34 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

//int execve(const char *pathname, char *const argv[], char *const envp[]);
//fd = open(argv[1], O_RDWR);
//write(fd, "1", 1)
// fd[0] - read
// fd[1] - write

int	main(int argc, char **argv) {
	int pipe_fd[2]; //nbr of cmds]
	if (pipe(pipe_fd) == -1)
	{
		perror("Error");
		return (1);
	}
	int	fd;
	int process_id;
	
	char *file = "/bin/echo";
	char *args2 = strcat(argv[1], " child process");
	char *args[] = {"/bin/echo", args2, NULL};
	char *env[] = {NULL};

	process_id = fork();
	if (process_id == -1)
		return (1);

	if (process_id == 0) // Child Process
	{
		//close(fd[0]);
		//write to the pipe = write(fd[1])
		int id2 = fork();
		if (id2 == 0)
			execve(file, args, env);
		char *buf = malloc(5556564545645);
		char *result = read(STDOUT_FILENO, buf, sizeof(buf));
		//write(fd[1], result, sizeof(result));
	
	} else { // Parent Process
		wait(NULL);// -> wait for child processes to finish
		//execve cmd2 avec l'output du child
		//read from the pipe = read(fd[0])
		printf("parent process");
	}





	

//	char *file = "/usr/bin/whereis";
//	char *args[] = {"/usr/bin/whereis", $ENV, NULL};
//	char *env[] = {"ENV=fjdjs", NULL};

	return (0);
}
