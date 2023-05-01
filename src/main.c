/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:45:02 by dborione          #+#    #+#             */
/*   Updated: 2023/05/01 13:29:58 by dborione         ###   ########.fr       */
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
//write(fd, "1", 1);

int	main(int argc, char **argv) {
	int pipe_fd[2]; //nbr of cmds]
	pipe(pipe_fd);
	// fd[0] - read
	// fd[1] - write
	int	fd;
	int process_id;
	
	char *file = "/bin/echo";
	char *args2 = strcat(argv[1], " child process");
	char *args[] = {"/bin/echo", args2, NULL};
	char *env[] = {NULL};

	process_id = fork();
	if (process_id == -1)
		return (1);

	if (process_id == 0)
	{
		//close(fd[0]);
		//write to the pipe = write(fd[1])
		int id2 = fork();
		if (id2 == 0)
			execve(file, args, env);
		wait(NULL);
		char *buf = malloc(5556564545645);
		char *result = read(1, buf, sizeof(buf));
		write(fd[1], result, sizeof(result));
	} else {
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
