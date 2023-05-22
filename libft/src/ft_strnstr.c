/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:50:45 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 12:35:22 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	int			i;
	int			j;
	int			len2;

	i = 0;
	j = 0;
	len2 = (int)len;
	if (!*needle)
		return (haystack);
	if (!haystack && len == 0)
		return (NULL);
	if (len2 < 0)
		len2 = ft_strlen(haystack);
	while (haystack[i] && i < len2)
	{
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < len2)
		{
			j++;
			if (needle[j] == '\0')
				return (&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
