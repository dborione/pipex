#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int	main() {
    int fd[2];
    pipe(fd);

    int pid;
    pid = fork();
    if (pid == 0) {//Child
    }

    int x = 0;



}
