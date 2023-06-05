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

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 2;
	pipex.infile_fd = 0;
	pipex.outfile_fd = 0;
	if (argc < 5)
		ft_error(EXIT_FAILURE, "wrg arg number");
	if (!ft_strncmp(argv[1], "here_doc", 8)
		&& ft_strlen(argv[1]) == 8)
			i = ft_here_doc(argv, &pipex, i);
	else if (argc == 6)
		ft_error(EXIT_FAILURE, "wrg here_doc");
	ft_open_files(argv, argc, &pipex);
	if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
		ft_error(EXIT_FAILURE, "qqqqqqqqq");
	close(pipex.infile_fd);
	while (i < (argc - 2))
		ft_fork(&pipex, argv[i++], env);
	ft_last_cmd(&pipex, argv[i], env);
	unlink(pipex.tmp_file);
	exit(0);
}