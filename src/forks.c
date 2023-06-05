/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:18:51 by dborione          #+#    #+#             */
/*   Updated: 2023/06/05 15:20:34 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_fds(int pipe_fd_0, int pipe_fd_1, int infile_fd)
{
	close(pipe_fd_0);
	close(pipe_fd_1);
	close(infile_fd);
}

int	ft_wait_pid(int pid, int *status)
{
	waitpid(pid, status, 0);
	if WIFEXITED(status)
		return (WEXITSTATUS(status));
	return (0);
}

void	ft_exec(t_cmd *cmd, char **env)
{
	int		exec;

	exec = execve(cmd->cmd_path, cmd->exec_arg, env);
	if (exec == -1)
		ft_error(CMD_NOT_FOUND, "command not found");
}


void	ft_first_child()
{
	close(fd[0][1]);
	
}

void	ft_child(int pipe_fd[2], t_pipex *pipex)
{
	if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		ft_error(0, "Error Duplicating Stdin");
	close(pipex->infile_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		ft_error(0, "Error Duplicating Stdout");
	close(pipe_fd[1]);
	ft_exec();
}

int	ft_fork(t_pipex *pipex, char *arg, char **env)
{
	int		pipe_fd[2];
	int		pid;

	if (pipe(pipe_fd) == -1)
		ft_error(0, "Error Opening Pipe");
	pid = fork();
	if (pid == -1)
		ft_error(0, "Error Creating Fork");
	if (pid == 0)
		ft_child();
	ft_parent();
}




























int	ft_fork2(t_pipex *pipex, char *arg, char **env)
{
	t_cmd	cmd;
	int		pipe_fd[2];
	int		status;
	int		pid;

	if (pipe(pipe_fd) == -1)
		ft_error(EXIT_FAILURE, "Open Pipe");
	pid = fork();
	if (pid == -1)
		ft_error(errno, "Open Fork");
	if (pid == 0)
	{
		if (!ft_get_path(env, arg, &cmd))
			ft_error(CMD_NOT_FOUND, "sd");
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_error(0, "__func__");
		ft_close_fds(pipe_fd[0], pipe_fd[1], pipex->infile_fd);
		exec(&cmd, env);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_error(0, " __func__");
	ft_close_fds(pipe_fd[0], pipe_fd[1], pipex->infile_fd);
	ft_wait_pid(pid, &status);
	return (1);
}

int	ft_last_cmd(t_pipex *pipex, char *arg, char **env)
{
	t_cmd	cmd;
	int		status;
	int		pid;

	pid = fork();
	if (!pid)
	{
		if (dup2(pipex->outfile_fd, STDOUT_FILENO) == -1)
			ft_error(0, "dup2");
		close(pipex->outfile_fd);
		if (ft_get_path(env, arg, &cmd) == -1)
			exit(0);
		exec(&cmd, env);
	}
	ft_wait_pid(pid, &status);
	return (1);
}
