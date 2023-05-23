#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

#include <sys/types.h>
#include <sys/wait.h>


typedef struct	s_cmd {
    char *cmd;
	char *cmd_param;
} t_cmd;

int ft_get_path(char **env, char *argv, t_cmd *cmd);
char	**ft_split(char const *s, char c);
int ft_error(int error_code, char *error_message);
char *ft_get_correct_path(char *correct_path, char **paths);
void ft_fork(int *pipe_fd, int pid, int pipe_write_or_read, int STD, t_cmd *cmd, char *arg);

#endif