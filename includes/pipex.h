#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

typedef struct	s_cmds {
    char *cmd1;
	char *cmd2;
	char *cmd1_arg;
    char *cmd2_arg;
} t_cmds;

int ft_get_path(char **env, char *argv, t_cmds *cmds);
char	**ft_split(char const *s, char c);
int ft_error(int error_code, char *error_message);
char *ft_get_correct_path(char *correct_path, char **paths);

#endif