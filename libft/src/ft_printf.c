/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:38:20 by secros            #+#    #+#             */
/*   Updated: 2024/11/20 19:20:54 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static ssize_t	ft_print_data(char s, va_list args)
{
	ssize_t	i;
	char	*str;

	i = -1;
	if (s == 'c')
		i = ft_putchar_fd(va_arg(args, int), 1);
	if (s == 's')
	{
		str = va_arg(args, char *);
		if (str)
			i = ft_putstr_fd(str, 1);
		else
			i = ft_putstr_fd("(null)", 1);
	}
	if (s == 'd' || s == 'i')
		i = ft_putnbr_fd(va_arg(args, int), 1);
	if (s == 'x' || s == 'X')
		i = hex_base((unsigned int) va_arg(args, int), s);
	if (s == 'u')
		i = ft_putnbr_fd((long) va_arg(args, unsigned int), 1);
	if (s == '%')
		i = ft_putchar_fd('%', 1);
	if (s == 'p')
		i = ft_putpointer(va_arg(args, unsigned long));
	return (i);
}

static ssize_t	ft_putlenstr(const char *s, size_t i)
{
	ssize_t	j;

	j = 0;
	while (s[i + j] && s[i + j] != '%')
		j++;
	j = write(1, &s[i], j);
	return (j);
}

int	ft_printstr(const char *s, va_list args)
{
	size_t	i;
	ssize_t	value;
	ssize_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			value = ft_print_data(s[++i], args);
			if (value == -1)
				return (-1);
			i++;
		}
		else
		{
			value = ft_putlenstr(s, i);
			if (value == -1)
				return (-1);
			i += value;
		}
		len += value;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	ssize_t	len;
	va_list	args;

	va_start(args, s);
	len = ft_printstr(s, args);
	if (len == -1)
	{
		write(2, "Oups something went wrong", 26);
		return (len);
	}
	va_end(args);
	return (len);
}
