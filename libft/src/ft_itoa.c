/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:55:52 by secros            #+#    #+#             */
/*   Updated: 2024/11/09 11:33:40 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(long n)
{
	unsigned int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long			nbr;
	unsigned int	i;
	char			*nb;
	unsigned int	is_neg;

	nbr = (long) n;
	is_neg = 0;
	i = ft_intlen(n);
	nb = (char *) malloc(sizeof(char) * (i + 1));
	if (!nb)
		return (NULL);
	if (nbr < 0)
	{
		nb[0] = '-';
		nbr *= -1;
		is_neg = 1;
	}
	nb[i] = '\0';
	while (i-- > is_neg)
	{
		nb[i] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (nb);
}
