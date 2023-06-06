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
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->p_data.env_paths = NULL;
	pipex->p_data.cmd_full = NULL;
	pipex->p_data.cmd_name_and_param = NULL;
	pipex->p_data.exec_arg = NULL;
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i;

	i = 2;
	ft_init_pipex(&pipex, env);
	//i = ft_check_here_doc(argc, argv, &pipex, i);
	//ft_open_files(argv, argc, &pipex);

	ft_get_path(argv[i], &pipex);
	printf("%s\n", pipex.p_data.exec_arg[0]);
	printf("%s\n", pipex.p_data.exec_arg[1]);
	printf("%s\n", pipex.p_data.exec_arg[2]);
	//printf("%s\n", pipex.p_data.exec_arg[3]);
	// if (dup2(pipex.infile_fd, STDIN_FILENO) == -1)
	// 	ft_error(EXIT_FAILURE, "dup2");
	// close(pipex.infile_fd);
	// while (i < (argc - 2))
	// 	ft_fork(&pipex, argv[i++], env);
	// ft_last_cmd(&pipex, argv[i], env);
	//unlink(pipex.tmp_file);
	exit(0);
}
