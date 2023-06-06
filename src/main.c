/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:45:02 by dborione          #+#    #+#             */
/*   Updated: 2023/06/06 17:22:09 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		pipe_fd[2];

	ft_init_pipex(&pipex, env);
	ft_open_files(argv, argc, &pipex);
	if (pipe(pipe_fd) == -1)
		ft_error(errno);
	ft_cmd1(&pipex, argv[2], pipe_fd);
	ft_cmd2(&pipex, argv[argc - 2], pipe_fd);
	ft_waitpids(&pipex);
	return (0);
}
