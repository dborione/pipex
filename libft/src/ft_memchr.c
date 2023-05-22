/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:17 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:45:27 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*s2;

	i = 0;
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == c2)
			return (&s2[i]);
		i++;
	}
	return (0);
}
