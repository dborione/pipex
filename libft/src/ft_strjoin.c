/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:22:10 by dborione          #+#    #+#             */
/*   Updated: 2022/10/19 15:28:49 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		buff;

	if (!s2 || !s1)
		return (NULL);
	buff = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc (sizeof(char) * buff);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, (ft_strlen(s1) + 1));
	ft_strlcat(s3, s2, buff);
	return (s3);
}
