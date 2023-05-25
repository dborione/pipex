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

	t_cmd	cmd1;
	t_cmd	cmd2;
	int 	pipe_fd[2];

	// if (argc != 5)
	//  	ft_error(EXIT_FAILURE, "Wrong Number of arguments");
	ft_get_path(env, argv[2], &cmd1);
	//printf("%s\n", cmd1.cmd);
	if (argv[3])
		ft_get_path(env, argv[3], &cmd2);

    if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe Error");

	ft_fork_cmd1(pipe_fd, &cmd1, argv[1]);
	cmd2.output = cmd1.output;
	if (argv[3])
		ft_fork_cmd2(pipe_fd, &cmd2, argv);

	close(pipe_fd[0]);
	close(pipe_fd[1]);
	
	exit(0);
}




































	//waitpid(pid1, NULL, 0);
	//waitpid(pid2, NULL, 0);



	// free(cmd1.cmd);
	// free(cmd1.cmd_arg);
	// free(cmd2.cmd);
	// free(cmd2.cmd_arg);

	// int child_status2;
	// int child_status1;
	// int	wstatus;
	// child_status1 = waitpid(pid, &wstatus, 0);
	// child_status2 = waitpid(pid2, NULL, 0);
	// if (WIFEXITED(wstatus)) //check if program terminated properly 
	// 	child_status2 = WEXITSTATUS(wstatus);
	//printf("%d\n", child_status1);
	//printf("%d\n", child_status2);
	//exit(child_status2);

	//return (0);

