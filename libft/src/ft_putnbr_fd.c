/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:42:48 by dborione          #+#    #+#             */
/*   Updated: 2022/10/14 11:57:31 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nbr == 2147483647)
		write(fd, "2147483647", 10);
	else if (nbr >= 0 && nbr < 10)
	{
		nbr = nbr + '0';
		write(fd, &nbr, 1);
	}
	else if (nbr < 0 && nbr > -2147483648)
	{
		write(fd, "-", 1);
		nbr = -nbr;
		ft_putnbr_fd(nbr, fd);
	}
	else if (nbr < 2147483647)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}
