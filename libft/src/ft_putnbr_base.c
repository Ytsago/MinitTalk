/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:12:19 by secros            #+#    #+#             */
/*   Updated: 2024/11/20 19:21:34 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putpointer(unsigned long long pt)
{
	ssize_t	i;

	if (pt == 0)
	{
		i = write(1, "(nil)", 5);
		if (i == -1)
			return (-1);
		return (i);
	}
	i = write(1, "0x", 2);
	if (i == -1)
		return (-1);
	return (i + hex_base(pt, 'x'));
}

ssize_t	hex_base(unsigned long long nb, int cap)
{
	char	hex[17];

	if (cap == 'x')
		ft_strlcpy(hex, "0123456789abcdef", 17);
	else
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	return (ft_putnbr_base(nb, hex, 16, 1));
}

ssize_t	ft_putnbr_base(unsigned long long nbr,
			char *base, unsigned int base_len, int fd)
{
	ssize_t	i;
	ssize_t	temp;

	i = 0;
	temp = 0;
	if (nbr >= base_len)
	{
		temp = ft_putnbr_base(nbr / base_len, base, base_len, fd);
		if (temp == -1)
			return (-1);
	}
	i += temp;
	if (ft_putchar_fd(base[nbr % base_len], fd) == -1)
		return (-1);
	return (i + 1);
}
