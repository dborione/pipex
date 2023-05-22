/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:43:57 by dborione          #+#    #+#             */
/*   Updated: 2022/10/26 13:05:42 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		start = 0;
		len = 0;
	}
	if ((start + len > s_len) || (len > s_len))
		len = s_len - start;
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, &s[start], len + 1);
	return (s2);
}
