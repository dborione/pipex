#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

//int execve(const char *pathname, char *const argv[], char *const envp[]);

int	main(int argc, char **argv) {
	int	fd;
	int process_id;
	
	char *file = "/bin/echo";
	char *args[] = {"echo", "$first", NULL};
	char *env[] = {"first=fdsfds", NULL};

	process_id = fork();
	if (process_id == -1)
		return (1);

	if (process_id == 0)
		execve(file, args, env);

		//recupere l'output
	else {
		wait(NULL);// -> wait for child processes to finish
		//execve cmd2 avec l'output du child
		printf("parent process");
	}




	//fd = open(argv[1], O_RDWR);
	//write(fd, "1", 1);
	

//	char *file = "/usr/bin/whereis";
//	char *args[] = {"/usr/bin/whereis", argv[1], NULL};
//	char *env[] = {NULL};


	return (0);
}
