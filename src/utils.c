/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:32:21 by dborione          #+#    #+#             */
/*   Updated: 2023/06/05 15:33:56 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_data_init(t_parsing_data *data, t_cmd *cmd)
{
	data->env_paths = NULL;
	data->cmd_full = NULL;
	data->cmd_path_clone = NULL;
	cmd->cmd_path = NULL;
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

void	ft_open_files(char **argv, int argc, t_pipex *pipex)
{
	if (pipex->infile_fd == 0)
	{
		if (access(argv[1], R_OK) == -1)
			ft_error(0, "infile open");
		pipex->infile_fd = open(argv[1], O_RDWR | O_CREAT, 0777);
		if (pipex->infile_fd == -1)
			ft_error(0, "infile open");
	}
	if (access(argv[argc - 1], R_OK) == -1)
		ft_error(0, "access2");
	pipex->outfile_fd = open(argv[argc - 1],
			O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (pipex->outfile_fd == -1)
		ft_error(0, "outfile open");
}

int	ft_error(int error_code, char *error_message)
{
	perror (error_message);
	exit(error_code);
}
