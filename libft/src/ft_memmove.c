/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:22:24 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:43:32 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	if (!dest && !src)
		return (0);
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = 0;
	if (dest2 > src2)
	{
		while (n > 0)
		{
			n--;
			dest2[n] = src2[n];
		}
	}
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
