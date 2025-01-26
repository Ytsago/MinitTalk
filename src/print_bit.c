/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:36:56 by secros            #+#    #+#             */
/*   Updated: 2025/01/26 01:57:25 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char	signal_received;

void	catch_signal(int signal, siginfo_t *sender, void *context)
{
	(void) signal;
	(void) sender;
	(void) context;
	signal_received = 1;
}

void	wait_respond()
{
	int	time;

	time = 0;
	while (!signal_received)
	{
		usleep(100);
		time += 100;
		if (time >= TIMEOUT)
		{
			write (2, "Error.\nNo respond from the server", 33);
			exit(1);
		}
	}
}	

void	send_bit(int pid, char *str)
{
	int	i;
	int	j;
	
	j = 0;
	while  (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (!signal_received)
				wait_respond();
			if (str[j] & (1 << i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			signal_received = 0;
			i++;
		}
		j++;
	}
}

void	signal_open(struct sigaction *back)
{
	sigemptyset(&back->sa_mask);
	sigaddset(&back->sa_mask, SIGUSR1);
	back->sa_sigaction = &catch_signal;
	sigaction(SIGUSR1, back, NULL);
}

int main(int ac, char **av)
{
	struct sigaction	back;
	signal_received = 1;
	if (ac != 3)
		return ((void) write(2, "Error\nBad Argument\n", 19), 1);
	signal_open(&back);
	send_bit(ft_atoi(av[1]), av[2]);
}