#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include "../libft/includes/libft.h"
#include "../get_next_line.h"

#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_cmd {
    char *cmd_path;
	char *cmd_param;
    char *file;
    char *ptr;
} t_cmd;

typedef struct s_pipex
{
    int infile_fd;
    int outfile_fd;
    t_cmd cmd;
} t_pipex;

int ft_get_path(char **env, char *arg, t_cmd *cmd);
char	**ft_split(char const *s, char c);
int ft_error(int error_code, char *error_message);
int ft_free_tab(char **tab);
void	ft_open_files(char **argv, int argc, t_pipex *pipex);
int	ft_fork(t_pipex *pipex, char **argv, char *arg, char **env);
void	exec(char **argv, t_cmd *cmd, char **env);
int ft_last_cmd(t_pipex *pipex, char **argv, char *arg, char **env);
int	ft_here_doc(char **argv, t_pipex *pipex, int i);

#endif