/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:14:10 by dborione          #+#    #+#             */
/*   Updated: 2023/06/05 15:18:36 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define CMD_NOT_FOUND 127
# define UNVALID_EXIT_CODE 128

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_parsing_data {
	char	**env;
	char	**env_paths;
	char	**cmd_name_and_param;
	char	**exec_arg;
	char	*cmd_full; //-> path + / + cmd_name_and_param[0]
}	t_parsing_data;

typedef struct s_pipex
{
	t_parsing_data p_data;
	char	*tmp_file;
	int		infile_fd;
	int		outfile_fd;
}	t_pipex;

int	ft_get_path(char *arg, t_pipex *pipex);
char	**ft_split(char const *s, char c);
// int		ft_error(int error_code, char *error_message);
// int		ft_free_tab(char **tab);
// void	ft_open_files(char **argv, int argc, t_pipex *pipex);
// int		ft_fork(t_pipex *pipex, char *arg, char **env);
// void	exec(t_cmd *cmd, char **env);
// int		ft_last_cmd(t_pipex *pipex, char *arg, char **env);
// int		ft_here_doc(char **argv, t_pipex *pipex, int i);
// void	ft_data_init(t_parsing_data *data, t_cmd *cmd);
// int		ft_free_tab(char **tab);
// int	ft_check_here_doc(int argc, char **argv, t_pipex *pipex, int i);

#endif
