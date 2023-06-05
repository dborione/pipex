/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:20:50 by dborione          #+#    #+#             */
/*   Updated: 2023/06/05 15:22:47 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_here_doc(char **argv, t_pipex *pipex, int i)
{
	char	*line;
	int		delimitor_len;
	int		out_clone;

	pipex->tmp_file = "tmp_file";
	pipex->infile_fd = open(pipex->tmp_file, O_RDWR | O_TRUNC | O_CREAT, 0777);
	delimitor_len = ft_strlen(argv[2]);
	line = get_next_line(STDIN_FILENO);
	if (!strncmp(line, argv[2], delimitor_len))
		return (i + 1);
	out_clone = dup(STDOUT_FILENO);
	if (dup2(pipex->infile_fd, out_clone) == -1)
		printf("2");
	while (ft_strncmp(argv[2], line, delimitor_len))
	{
		ft_putstr_fd(line, out_clone);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(out_clone);
	free(line);
	return (i + 1);
}
