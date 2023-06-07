/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:14:10 by dborione          #+#    #+#             */
/*   Updated: 2023/06/07 14:22:13 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PERM_DENIED 126
# define CMD_NOT_FOUND 127

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_parsing_data
{
	char	**env;
	char	**env_paths;
	char	**full_arg;
	char	**exec_arg;
	char	*cmd_full;
}	t_parsing_data;

typedef struct s_pipex
{
	t_parsing_data	p_data;
	char			*tmp_file;
	int				infile_fd;
	int				outfile_fd;
	int				pid1;
	int				pid2;
	int				exit_status;
}	t_pipex;

void	ft_init_pipex(t_pipex *pipex, char **env);
void	ft_open_files(char **argv, int argc, t_pipex *pipex);
void	ft_cmd1(t_pipex *pipex, char *argv, int *pipe_fd);
void	ft_cmd2(t_pipex *pipex, char *argv, int *pipe_fd);
int		ft_fork(int pid, t_pipex *pipex);
int		ft_get_path(char *arg, t_pipex *pipex);
void	ft_dup2(int fd1, int fd2, t_pipex *pipex);
void	ft_exec(t_pipex *pipex);
int		ft_error(int error_code, t_pipex *pipex);
int		ft_free_all(t_pipex *pipex);
int		ft_free_tab(char **tab);
void	ft_waitpids(t_pipex *pipex);

#endif
