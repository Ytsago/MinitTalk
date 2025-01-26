/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:16:15 by secros            #+#    #+#             */
/*   Updated: 2025/01/26 01:57:58 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	bit;

void	catch_int(int sig_num, siginfo_t *sender, void *context)
{
	(void) context;
	if (sig_num == SIGUSR1)
		bit = '0';
	else if (sig_num == SIGUSR2)
		bit = '1';
	usleep(100);
	kill(sender->si_pid, SIGUSR1);
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
		if (c[i] == '1')
			output |= (1 << i);
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

void	signal_open(struct sigaction *sender)
{
	sigemptyset(&sender->sa_mask);
	sigaddset(&sender->sa_mask, SIGUSR1);
	sigaddset(&sender->sa_mask, SIGUSR2);
	sender->sa_sigaction = &catch_int;
	sender->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, sender, NULL);
	sigaction(SIGUSR2, sender, NULL);
}

int main()
{
	char	bits[9];
	struct sigaction	sender;

	bits[8] = '\0';
	bit = -1;
	ft_printf("Server PID : [%d]\n", getpid());
	signal_open(&sender);
	while (1)
	{
		if (bit == '0' || bit == '1')
		{
			if (collect_bits(bits) == 8)
				ft_printf("%c", bit_to_char(bits));
		}
	}
}