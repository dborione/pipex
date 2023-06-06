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

	ft_init_pipex(&pipex, env);
	//i = ft_check_here_doc(argc, argv, &pipex, i);
	ft_open_files(argv, argc, &pipex);
	ft_do_pipe(&pipex, argv[2], argv[argc - 2]);
	//unlink(pipex.tmp_file);
	return (0);
}
