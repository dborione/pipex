/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:51:51 by dborione          #+#    #+#             */
/*   Updated: 2022/10/13 10:27:47 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count > 65535 || size > 65535)
		return (0);
	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}
