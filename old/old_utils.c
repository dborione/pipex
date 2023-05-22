#include "../includes/pipex.h"

int ft_error(int error_code, char *error_message)
{
    perror(error_message);
    return (error_code);
}

int ft_get_command()
{
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
		return (ft_error(1, "Open Pipe Error"));

    int pid = fork();
    if (pid == -1)
        return (ft_error(1, "Create Fork Error"));

    if (pid == 0) //Child
    {
        int tmp_file;
        tmp_file = open("env_output.txt", O_RDWR | O_CREAT, 0777); //0777: rights for everybody
        if (tmp_file == -1)
            return (1, "Open File Error");
        dup2(tmp_file, STDOUT_FILENO);
        close(tmp_file);

        char *arg[] = {"/usr/bin/", "env", NULL};
        int error = execve("/usr/bin/", arg, NULL);
        if (error == -1)
            return (ft_error(1, "cmd execution error"));
       // while((dup2(pipe_fd[1], STDOUT_FILENO) == -1)); //Send output to write end of pipe
		close(pipe_fd[1]);
    }
    close(pipe_fd[1]);
    //int tmp_file2 = open("env_output", O_RDONLY);
    //read(pipe_fd[0], str, sizeofstr)
    //read from read end of pipe
    //open new file, o_Create
    //write content of pipe in new file

    //parse new file until PATH, strcmp
    wait(NULL);
    return (0);
}

int main()
{
    return (ft_get_command());
}