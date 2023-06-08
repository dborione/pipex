/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:16:00 by dborione          #+#    #+#             */
/*   Updated: 2023/06/06 17:17:49 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_cmd1(t_pipex *pipex, char *argv, int *pipe_fd)
{
	ft_get_path(argv, pipex);
	pipex->pid1 = ft_fork(pipex->pid1, pipex);
	if (pipex->pid1 == 0)
	{
		close(pipe_fd[0]);
		ft_dup2(pipex->infile_fd, STDIN_FILENO, pipex);
		ft_dup2(pipe_fd[1], STDOUT_FILENO, pipex);
		ft_exec(pipex);
	}
}

void	ft_cmd2(t_pipex *pipex, char *argv, int *pipe_fd)
{
	ft_get_path(argv, pipex);
	pipex->pid2 = ft_fork(pipex->pid2, pipex);
	if (pipex->pid2 == 0)
	{
		close(pipe_fd[1]);
		ft_dup2(pipe_fd[0], STDIN_FILENO, pipex);
		ft_dup2(pipex->outfile_fd, STDOUT_FILENO, pipex);
		ft_exec(pipex);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	ft_waitpids(pipex);
}
