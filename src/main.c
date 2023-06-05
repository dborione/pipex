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

int	ft_init_pipex(t_pipex *pipex)
{
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 2;
	ft_init_pipex(&pipex);
	i = ft_check_here_doc(argc, argv, &pipex, i);
	ft_open_files(argv, argc, &pipex);
	// if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
	// 	ft_error(EXIT_FAILURE, "dup2");
	// close(pipex.infile_fd);
	while (i < (argc - 2))
		ft_fork(&pipex, argv[i++], env);
	ft_last_cmd(&pipex, argv[i], env);
	unlink(pipex.tmp_file);
	exit(0);
}
