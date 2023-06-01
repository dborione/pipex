#include "../includes/pipex.h"

int	ft_here_doc(char **argv, t_pipex *pipex, int i)
{
	char	*line;
	int		delimitor_len;

	pipex->tmp_file = "tmp_file";
	//pipex->infile_fd 
    pipex->infile_fd = open(pipex->tmp_file, O_RDWR | O_CREAT, 0777);
	if (pipex->infile_fd == -1)
		exit(2);
	// if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
    //     write(STDIN_FILENO, ">", 1);
   // close(pipex->infile_fd);
    // if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
	//  	write(STDERR_FILENO, "erro1", 5);
    
	delimitor_len = ft_strlen(argv[2]);
	line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(argv[2], line, delimitor_len))
	{
		//write(STDIN_FILENO, ">", 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
    // if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
	//  	write(STDERR_FILENO, "erro1", 5);
	free(line);
	return(i + 1);
}