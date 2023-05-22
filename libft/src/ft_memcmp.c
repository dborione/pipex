/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:20:48 by dborione          #+#    #+#             */
/*   Updated: 2022/10/10 11:43:14 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*cast_s1;
	unsigned char		*cast_s2;

	i = 0;
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cast_s2[i] != cast_s1[i])
			return (cast_s1[i] - cast_s2[i]);
		i++;
	}
	return (0);
}
