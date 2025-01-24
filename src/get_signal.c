/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:16:15 by secros            #+#    #+#             */
/*   Updated: 2025/01/24 18:49:37 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include "ft_printf.h"
#include "minitalk.h"

char	bit;

void	catch_int(int sig_num)
{
	if (sig_num == 10)
		bit = '0';
	else if (sig_num == 12)
		bit = '1';
}

char	bit_to_char(char *c)
{
	int		i;
	char	output;

	i = 0;
	output = 0;
	while (i <= 7)
	{
		if (c[i] == '0')
			output |= (0 << i);
			// ft_printf("%c, ", c[i]);
		if (c[i] == '1')
			output |= (1 << i);
			// ft_printf("%c, ", c[i]);
		i++;
	}
	return (output);
}

int	collect_bits(char bits[9])
{
	static int	i = 0;

	i = i % 8;
	bits[i] = bit;
	bit = -1;
	i++;
	return (i);
}

/* void	print_messgae(char c)
{
	static char *str;
	int	i;

	i = 0;
} */

int main()
{
	char	bits[9];

	bits[8] = '\0';
	bit = -1;
	ft_printf("Server PID : [%d]\n", getpid());
	signal(SIGUSR1, catch_int);
	signal(SIGUSR2, catch_int);
	while (1)
	{
		if (bit != -1)
		{
			if (collect_bits(bits) == 8)
				ft_printf("%c", bit_to_char(bits));
		}
	}
}