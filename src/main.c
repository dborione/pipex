/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:45:02 by dborione          #+#    #+#             */
/*   Updated: 2023/05/03 13:15:39 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env) {

	t_pipex	pipex;
	t_cmd	cmd;
	int		i;

	i = 2;
	if (argc < 5)
	 	ft_error(EXIT_FAILURE, "arg nbr");
	ft_open_files(argv, argc, &pipex);
	if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
		ft_error(0, "fdfds1");
	close(pipex.infile_fd);
	while (i < (argc - 2))
	{
		if (ft_get_path(env, argv[i], &cmd) == -1)
			exit(0);
		ft_fork(&pipex, argv, argv[i], env);
		i++;
	}
	ft_last_cmd(&pipex, argv, argv[i], env);
	exit(0);
}