/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:20:00 by cle-gran          #+#    #+#             */
/*   Updated: 2021/10/28 18:52:07 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	no_nbr(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

void	send_sign(pid_t pid_server, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(1500);
		if (c & 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		c = c >> 1;
		i++;
	}
}

void	send_char(pid_t pid_server, char *str)
{
	while (*str)
	{
		send_sign(pid_server, *str);
		str++;
	}
	send_sign(pid_server, *str);
}

int	main(int ac, char **av)
{
	int	pid_server;

	if (ac != 3 || no_nbr(av[1]))
	{
		ft_putstr("Wrong arguments, try again \n");
		return (0);
	}
	pid_server = ft_atoi(av[1]);
	send_char(pid_server, av[2]);
	return (0);
}
