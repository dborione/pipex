#include "../includes/pipex.h"

int	ft_here_doc(char **argv, t_pipex *pipex, int i)
{
	char	*line;
	int		delimitor_len;

	pipex->tmp_file = "tmp_file";

	int tmp_fd = open(pipex->tmp_file, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (pipex->infile_fd == -1)
		printf("2");
	pipex->infile_fd = dup(tmp_fd);
	delimitor_len = ft_strlen(argv[2]);
	line = get_next_line(STDIN_FILENO);
	if (!strncmp(line, argv[2], delimitor_len))
		return(i + 1);

	int out_clone = dup(STDOUT_FILENO);
	if (dup2(pipex->infile_fd, out_clone) == -1)
        printf("2");
	close(tmp_fd);
	while (ft_strncmp(argv[2], line, delimitor_len))
	{
		ft_putstr_fd(line, out_clone);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(out_clone);
	free(line);
	return(i + 1);
}