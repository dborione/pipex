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

//< infile cat | lsof -c pipex > outfile
//./pipex infile cat "lsof -c pipex" outfile

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
  	int pipe_fd[2];

	ft_init_pipex(&pipex, env);
	//i = ft_check_here_doc(argc, argv, &pipex, i);

	ft_open_files(argv, argc, &pipex);
	if (pipe(pipe_fd) == -1)
	  ft_error(0, "Error Opening Pipe");
	ft_cmd1(&pipex, argv[2], pipe_fd);
  	ft_cmd2(&pipex, argv[argc - 2], pipe_fd);
  	ft_waitpids(&pipex);

	//unlink(pipex.tmp_file);
	return (0);
}
