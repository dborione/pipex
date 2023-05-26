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

//pipex file1 cmd1 cmd2 file2
//int execve(const char *pathname, char *const argv[], char *const envp[]);
//fd = open(argv[1], O_RDWR);
// fd[0] - read
// fd[1] - write
// dup2(file_fd, STDIN)
//	dup2(pipe_fd, STDOUT)

//dip2(file, 1)
//pipe, 0

int	main(int argc, char **argv, char **env) {

	t_pipex	pipex;
	int		i;

	i = 2;
	if (argc != 5)
	 	ft_error(EXIT_FAILURE, "Wrong Number of arguments");
	ft_open_files(argv, argc, &pipex);
	//ft_fork(&pipex, argv, argv[i], env);
	while (i < (argc - 1))
		ft_fork(&pipex, argv, argv[i++], env);
	dup2(pipex.outfile_fd, STDOUT_FILENO);

	char *arg[] = {"/bin/cat", "-e", argv[argc - 1], NULL};
	if (execve("/bin/cat", arg, NULL) == -1)
        ft_error(0, "cmd execution error");
	exit(0);
}