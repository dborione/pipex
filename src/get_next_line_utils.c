/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:28:13 by dborione          #+#    #+#             */
/*   Updated: 2022/12/06 11:55:20 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen_gnl(src);
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen_gnl(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = ft_strlen_gnl(dst);
	i = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[i] && (i < (dstsize - dstlen - 1)))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strrchr_gnl(char *str, int c)
{
	int		len;

	len = ft_strlen_gnl(str);
	while (len != -1)
	{
		if (str[len] == (unsigned char)c)
			return (&str[len]);
		len--;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char		*s3;
	size_t		buf;

	if (!s2 || !s1)
	{
		free(s1);
		return (NULL);
	}
	buf = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	s3 = malloc(sizeof(*s3) * buf);
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy_gnl(s3, s1, (ft_strlen_gnl(s1) + 1));
	ft_strlcat_gnl(s3, s2, buf);
	free(s1);
	//free(s2);
	return (s3);
}
