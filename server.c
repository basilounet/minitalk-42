/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:17:44 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/14 17:38:18 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static void	print_banner(void)
{
	ft_printf("\033[0;33m\
╔═══════════════════════════════════════════════════════╗\n\
║\t\t\t\t\t\t\t║\n\
║\033[0;96m\t▓     ▓  ▓  ▓   ▓  ▓  ▓▓▓   ▓▓▓   ▓    ▓  ▓\t\033[0;33m║\n\
║\033[0;96m\t▓▓   ▓▓  ▓  ▓▓  ▓  ▓   ▓   ▓   ▓  ▓    ▓ ▓ \t\033[0;33m║\n\
║\033[0;96m\t▓ ▓ ▓ ▓  ▓  ▓ ▓ ▓  ▓   ▓   ▓▓▓▓▓  ▓    ▓▓  \t\033[0;33m║\n\
║\033[0;96m\t▓  ▓  ▓  ▓  ▓  ▓▓  ▓   ▓   ▓   ▓  ▓    ▓ ▓ \t\033[0;33m║\n\
║\033[0;96m\t▓     ▓  ▓  ▓   ▓  ▓   ▓   ▓   ▓  ▓▓▓  ▓  ▓\t\033[0;33m║\n\
║                                                       \033[0;33m║\n\
║\033[0;96m\t ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\t\033[0;33m║\n\
╩                                                       ╩\n\
\033[0;94m\t\t\tpid :%d\t\t\033[0;33m\n\
╦                                                       ╦\n\
║\033[0;34m\t ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\t\033[0;33m║\n\
║\t\t\t\t\t\t\t║\n\
║\033[0;34m\t▒     ▒  ▒  ▒   ▒  ▒   ▒   ▒   ▒  ▒▒▒  ▒  ▒\t\033[0;33m║\n\
║\033[0;34m\t▒  ▒  ▒  ▒  ▒  ▒▒  ▒   ▒   ▒   ▒  ▒    ▒ ▒ \t\033[0;33m║\n\
║\033[0;34m\t▒ ▒ ▒ ▒  ▒  ▒ ▒ ▒  ▒   ▒   ▒▒▒▒▒  ▒    ▒▒  \t\033[0;33m║\n\
║\033[0;34m\t▒▒   ▒▒  ▒  ▒▒  ▒  ▒   ▒   ▒   ▒  ▒    ▒ ▒ \t\033[0;33m║\n\
║\033[0;34m\t▒     ▒  ▒  ▒   ▒  ▒  ▒▒▒   ▒▒▒   ▒    ▒  ▒\t\033[0;33m║\n\
║\t\t\t\t\t\t\t║\n\
╚═══════════════════════════════════════════════════════╝\n\033[39m",
		getpid());
}

void	my_sig_handler(int signal, siginfo_t *info, void *s)
{
	static int	c = 0b0;
	static int	i = 0;

	(void)s;
	if (i <= 7)
	{
		c <<= 1;
		if (signal == SIGUSR1)
			c |= 0b1;
		i++;
		kill(info->si_pid, SIGUSR2);
	}
	if (i >= 8)
	{
		ft_printf("%c", c);
		c = 0b0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
		return (1);
	print_banner();
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = &my_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		continue ;
}
