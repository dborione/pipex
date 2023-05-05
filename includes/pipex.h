#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"

char **ft_get_cmd(char **env);
char	**ft_split(char const *s, char c);
int ft_error(int error_code, char *error_message);

#endif