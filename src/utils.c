/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:19:54 by dborione          #+#    #+#             */
/*   Updated: 2023/06/06 17:24:46 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **env)
{
	pipex->p_data.argv = NULL;
	pipex->p_data.env = env;
	pipex->p_data.env_paths = NULL;
	pipex->p_data.full_arg = NULL;
	pipex->p_data.exec_arg = NULL;
	pipex->p_data.cmd_full = NULL;
	pipex->infile_fd = 0;
	pipex->outfile_fd = 0;
	pipex->pid1 = 0;
	pipex->pid2 = 0;
	pipex->exit_status = 0;
}

void	ft_open_files(char **argv, int argc, t_pipex *pipex)
{
	if (access(argv[1], F_OK) == -1)
	{
		pipex->p_data.argv = argv[1];
		ft_error(NO_FILE, pipex);
	}
	pipex->outfile_fd = open(argv[argc - 1],
		O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (pipex->outfile_fd == -1)
	{
		pipex->p_data.argv = argv[argc - 1];
		ft_error(NO_FILE, pipex);
	}
	pipex->infile_fd = open(argv[1], O_RDONLY, 0777);
	if (pipex->infile_fd == -1)
	{
		pipex->p_data.argv = argv[1];
		ft_error(NO_FILE, pipex);
	}
}

int	ft_error(int error_code, t_pipex *pipex)
{
	pipex->exit_status = error_code;
	if (error_code == CMD_NOT_FOUND)
	{
		ft_putstr_fd(pipex->p_data.argv, STDERR_FILENO);
		ft_putstr_fd(" :command not found\n", STDERR_FILENO);
	}
	else
		perror(pipex->p_data.argv);
	ft_free_all(pipex);
	exit(error_code);
}

int	ft_free_all(t_pipex *pipex)
{
	if (pipex->p_data.env_paths)
		ft_free_tab(pipex->p_data.env_paths);
	if (pipex->p_data.full_arg)
		ft_free_tab(pipex->p_data.full_arg);
	if (pipex->p_data.exec_arg)
		ft_free_tab(pipex->p_data.exec_arg);
	if (pipex->p_data.cmd_full)
		free(pipex->p_data.cmd_full);
	return (0);
}

int	ft_free_tab(char **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		free(tab[x++]);
	free(tab);
	return (0);
}
