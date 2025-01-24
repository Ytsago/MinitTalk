/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:32:25 by secros            #+#    #+#             */
/*   Updated: 2024/11/19 11:18:48 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_putnbr_rec(long nbr, int fd)
{
	ssize_t	temp;
	ssize_t	i;

	i = 0;
	temp = 0;
	if (nbr > 9)
		temp = ft_putnbr_rec(nbr / 10, fd);
	if (temp == -1)
		return (-1);
	i += temp;
	if (ft_putchar_fd(nbr % 10 + 48, fd) == -1)
		return (-1);
	return (i + 1);
}

ssize_t	ft_putnbr_fd(long nbr, int fd)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		if (write(fd, "-", 1) == -1)
			return (-1);
		else
			i = 1;
	}
	return (i + ft_putnbr_rec(nbr, fd));
}
