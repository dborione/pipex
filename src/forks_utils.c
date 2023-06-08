/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:18:10 by dborione          #+#    #+#             */
/*   Updated: 2023/06/06 17:21:35 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_waitpids(t_pipex *pipex)
{
	int	status;

	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
	pipex->exit_status = WEXITSTATUS(status);
}

void	ft_exec(t_pipex *pipex)
{
	int		exec;

	exec = execve(pipex->p_data.exec_arg[0],
			pipex->p_data.exec_arg, pipex->p_data.env);
	if (exec == -1)
		ft_error(CMD_NOT_FOUND, pipex);
}

void	ft_dup2(int fd1, int fd2, t_pipex *pipex)
{
	if (dup2(fd1, fd2) == -1)
		ft_error(2, pipex);
	close(fd1);
}

int	ft_fork(int pid, t_pipex *pipex)
{
	pid = fork();
	if (pid == -1)
		ft_error(2, pipex);
	return (pid);
}
