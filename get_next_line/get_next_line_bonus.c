/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:24:22 by dborione          #+#    #+#             */
/*   Updated: 2023/04/14 17:24:25 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		read_ret;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(stash));
	read_ret = 1;
	while (!ft_strrchr(stash, '\n') && (read_ret != 0))
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(stash);
			return (ft_free(buf));
		}
		buf[read_ret] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (ft_free(buf));
	}
	free(buf);
	if (*stash == '\0')
		return (ft_free(stash));
	return (stash);
}

char	*ft_copy_line(char *stash)
{
	char		*line;
	int			i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, (i + 2));
	return (line);
}

char	*ft_copy_stash(char *stash)
{
	char		*new_stash;
	int			stash_len;
	int			i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	stash_len = ft_strlen(stash) - i + 1;
	new_stash = malloc(sizeof(*new_stash) * stash_len);
	if (!new_stash)
		return (NULL);
	if (stash_len == 1)
		ft_strlcpy(new_stash, &(stash[i]), stash_len);
	else
		ft_strlcpy(new_stash, &(stash[i + 1]), stash_len);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(*stash));
		if (!stash[fd])
			return (NULL);
		*(stash[fd]) = '\0';
	}
	stash[fd] = ft_read_line(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_copy_line(stash[fd]);
	if (!line)
		return (ft_free(stash[fd]));
	stash[fd] = ft_copy_stash(stash[fd]);
	if (!stash[fd])
	{
		free(line);
		return (ft_free(stash[fd]));
	}
	return (line);
}
