/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 09:37:48 by secros            #+#    #+#             */
/*   Updated: 2025/01/30 18:47:30 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_signal_received;

void	catch_signal(int sig_num, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sig_num == SIGUSR1)
		g_signal_received = 1;
}

int	send_bits(char c, int pid, int i)
{
	static int	time;

	if (g_signal_received == 1)
	{
		time = 0;
		g_signal_received = 0;
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		else
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		return (1);
	}
	else
	{
		usleep(10);
		time += 10;
		if (time >= TIMEOUT)
			return (-2);
		else
			return (0);
	}
}

int	send_str(char *str, int pid)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	j = 0;
	while (i == 0 || str[i - 1])
	{
		x = send_bits(str[i], pid, j);
		if (x == 1)
			j++;
		else if (x == -1)
			return (-1);
		else if (x == -2)
			return (-2);
		if (j == 8)
		{
			j = 0;
			i++;
		}
	}
	usleep(10);
	if (g_signal_received == 1)
		return (0);
	return (1);
}

int	sig_init(struct sigaction *sig)
{
	ft_bzero(sig, sizeof(struct sigaction));
	if (sigemptyset(&sig->sa_mask) == -1)
		return (-1);
	if (sigaddset(&sig->sa_mask, SIGUSR1) == -1)
		return (-1);
	sig->sa_sigaction = &catch_signal;
	if (sigaction(SIGUSR1, sig, NULL) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction	sig;
	int					x;
	int					y;

	if (ac != 3)
		return ((void) write(2, "Error.\nBad arguments", 21), 1);
	if (sig_init(&sig) == -1)
		return ((void) write(2, "Error.\nCouldn't create connection", 33), 1);
	g_signal_received = 1;
	y = 0;
	while (av[1][y])
		if (ft_isdigit(av[1][y++]) == 0)
			return ((void) write(2, "Error.\nPid is not numeric", 25), 1);
	x = send_str(av[2], ft_atoi(av[1]));
	if (x == -1)
		return ((void) write(2, "Error.\nCouldn't send signal", 27), 1);
	else if (x == -2)
		return ((void) write(2, "Error.\nTime out", 15), 1);
	else if (x == 0)
		return ((void) write(1, "Message delivered !\n", 20), 0);
}
