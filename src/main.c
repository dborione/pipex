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
	ft_get_path(env, argv[1], &cmd);
	// ft_open_files(argv, argc, &pipex);
	// if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
	// 	write(STDERR_FILENO, "error", 5);
	// close(pipex.infile_fd);
	// while (i < (argc - 2))
	// 	ft_fork(&pipex, argv, argv[i++], env);
	// ft_last_cmd(&pipex, argv, argv[i], env);
	//free(cmd.cmd_path);
	//free(cmd.cmd_param);
	exit(0);
}