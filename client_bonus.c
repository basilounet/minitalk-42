/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:17:36 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/16 10:47:42 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int		g_signal_received = 0;

void	wait_response(void)
{
	int	i;

	i = 0;
	while (i < 25000)
	{
		usleep(1);
		if (g_signal_received)
		{
			g_signal_received = 0;
			return ;
		}
		i++;
	}
	ft_printf("Error\nServer not found");
	exit(1);
}

void	sig_handler(int signo)
{
	if (signo == SIGUSR2)
		g_signal_received = 1;
}

void	send_character(int pid, int c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (c >> (7 - j) & 0b1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		wait_response();
		j++;
	}
	usleep(1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		return (1);
	pid = ft_atol(av[1]);
	if (pid <= 0 || pid > 2147483647 || ft_strlen(av[1]) > 11)
		return (0);
	signal(SIGUSR2, sig_handler);
	while (av[2][i])
		send_character(pid, av[2][i++]);
	send_character(pid, '\n');
}
