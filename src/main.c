/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:45:02 by dborione          #+#    #+#             */
/*   Updated: 2023/06/05 15:23:41 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_init_pipex(t_pipex *pipex, char **env)
{
	pipex->p_data.env = env;
	pipex->p_data.env_paths = NULL;
	pipex->p_data.cmd_full = NULL;
	pipex->p_data.cmd_name_and_param = NULL;
	pipex->p_data.exec_arg = NULL;
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->pid1 = 0;
	pipex->pid2 = 0;
	return (1);
}

void	ft_waitpids(t_pipex *pipex)
{
	int	status;
	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 2;
	ft_init_pipex(&pipex, env);
	//i = ft_check_here_doc(argc, argv, &pipex, i);
	ft_open_files(argv, argc, &pipex);
	ft_cmd1(&pipex, argv[i]);
	ft_cmd2(&pipex, argv[argc - 1]);
	ft_waitpids(&pipex);
	//unlink(pipex.tmp_file);
	exit(0);
}
