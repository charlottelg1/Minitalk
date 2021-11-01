/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:07:27 by cle-gran          #+#    #+#             */
/*   Updated: 2021/10/28 17:53:26 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/signal.h>
# include <signal.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		checkoverflow(char *str, int sign);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);

#endif
