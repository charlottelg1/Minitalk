/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:23:10 by cle-gran          #+#    #+#             */
/*   Updated: 2021/10/28 18:51:53 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_gest(int signum)
{
	static int	i;
	static char	c;

	if (signum == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sigstruc;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_putnbr((int)pid);
	ft_putchar('\n');
	sigstruc.sa_handler = &ft_gest;
	sigemptyset(&sigstruc.sa_mask);
	sigstruc.sa_flags = 0;
	sigaction(SIGUSR1, &sigstruc, NULL);
	sigaction(SIGUSR2, &sigstruc, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
