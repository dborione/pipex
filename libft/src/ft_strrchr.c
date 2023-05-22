/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:55:33 by dborione          #+#    #+#             */
/*   Updated: 2022/10/11 16:46:21 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		len;

	len = ft_strlen(str);
	while (len > -1)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
