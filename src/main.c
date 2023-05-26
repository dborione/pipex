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
	int		i;

	i = 2;
	if (argc != 5)
	 	ft_error(EXIT_FAILURE, "arg nbr");
	ft_open_files(argv, argc, &pipex);
	//if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
	//	ft_error(0, "fdfds1");
	//write(STDIN_FILENO, "fd", 2);
	//while (i < (argc - 1))
		ft_fork(&pipex, argv, argv[i], env, argc);
	//if (dup2(pipex.outfile_fd, STDIN_FILENO) == -1)
	//	ft_error(0, "fdfds4");

	// char *arg[] = {"/bin/cat", "-e", "outfile", NULL};
	// if (execve("/bin/cat", arg, env) == -1)
    //     ft_error(0, "cmd exec2");
	exit(0);
}