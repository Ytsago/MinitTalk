/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:19:28 by secros            #+#    #+#             */
/*   Updated: 2025/01/30 18:39:18 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*append_char(char *str, char c)
{
	int		size;
	char	*f_str;

	size = ft_strlen(str);
	f_str = malloc(sizeof(char) * (2 + size));
	if (!f_str)
		return (free (str), NULL);
	f_str[size + 1] = '\0';
	f_str[size] = c;
	while (size--)
		f_str[size] = str[size];
	free(str);
	return (f_str);
}

void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c;
	static char	*str;

	(void) context;
	if (sig_num == SIGUSR1)
		c &= ~(1 << i++);
	else if (sig_num == SIGUSR2)
		c |= (1 << i++);
	if (i == 8)
	{
		i = 0;
		str = append_char(str, c);
		if (!str)
			return ((void) write(2, "Malloc Error\n", 13), exit(1));
		if (c == '\0')
		{
			ft_putendl_fd(str, 1);
			free(str);
			str = NULL;
		}
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		return ((void) write(2, "Error\nCouldn't send signal", 26), free(str));
}

int	sig_init(struct sigaction *sig)
{
	ft_bzero(sig, sizeof(struct sigaction));
	if (sigemptyset(&sig->sa_mask) == -1)
		return (-1);
	if (sigaddset(&sig->sa_mask, SIGUSR1) == -1)
		return (-1);
	if (sigaddset(&sig->sa_mask, SIGUSR2) == -1)
		return (-1);
	sig->sa_flags = SA_SIGINFO;
	sig->sa_sigaction = &signal_handler;
	if (sigaction(SIGUSR1, sig, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, sig, NULL) == -1)
		return (-1);
	return (0);
}

int	main(void)
{
	struct sigaction	sig;

	if (sig_init(&sig) == -1)
		return ((void) write(2, "Error.\n", 7), 2);
	ft_printf("Server PID : [%d]\n", getpid());
	while (1)
	{
		pause();
	}
}
