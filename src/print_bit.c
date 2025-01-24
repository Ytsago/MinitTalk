/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:36:56 by secros            #+#    #+#             */
/*   Updated: 2025/01/24 19:03:46 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "signal.h"
#include "ft_printf.h"
#include "minitalk.h"

// char	*char_to_bit(char c)
// {
// 	int		i;
// 	char	*bits;

// 	i = 0;
// 	bits = malloc(sizeof(char)* 9);
// 	if (!bits)
// 		return (NULL);
// 	while (i <= 7)
// 	{
// 		if (c & (1 << i))
// 			send_bit()
// 		else
// 			bits[i] = '0';
// 		i++;
// 	}
// 	bits[8] = '\0';
// 	return (bits);
// }

void	send_bit(int pid, char *str)
{
	int	i;
	int	j;

(void) pid;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (str[j] & (1 << i))
				kill(pid, SIGUSR2);
				// ft_printf("0, ");
			else
				kill(pid, SIGUSR1);
				// ft_printf("1, ");
			usleep(5);
			i++;
			//ft_printf("world");
		}
		// ft_printf("\n");
		j++;
	}
}

int main(int ac, char **av)
{
	int	i;
	struct sigaction sa;

	ft_bzero((void*) &sa, sizeof(struct sigaction));
	i = 0;
	if (ac != 3)
		return ((void) write(2, "Error\nBad Argument\n", 19), 1);
	send_bit(ft_atoi(av[1]), av[2]);
}