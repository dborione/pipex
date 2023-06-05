/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:51:16 by dborione          #+#    #+#             */
/*   Updated: 2023/04/14 17:24:46 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strjoin_gnl(char *s1, char const *s2);
size_t	ft_strlen_gnl(const char *str);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
char	*ft_strrchr_gnl(char *str, int c);

#endif
