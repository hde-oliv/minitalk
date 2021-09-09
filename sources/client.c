/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:19 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/29 17:06:00 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minitalk.h"

static int	g_lock;

void	response_handler(int sig)
{
	(void)sig;
	g_lock = 1;
}

void	send_bit(int pid, int bit)
{
	if (!bit)
	{
		if (kill(pid, SIGUSR1))
			err(KILL_ERR);
	}
	else
	{
		if (kill(pid, SIGUSR2))
			err(KILL_ERR);
	}
	while (g_lock == 0)
		;
	g_lock = 0;
}

void	send_zero(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, (0 >> i) & 0x01);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					pid;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
		exit(1);
	pid = ft_atoi(*(argv + 1));
	str = (*(argv + 2));
	ft_bzero(&sa, sizeof(struct sigaction));
	sa.sa_handler = response_handler;
	if (sigaction(SIGUSR2, &sa, NULL))
		err(SIGA_ERR);
	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			send_bit(pid, (*str >> i) & 0x01);
			i++;
		}
		str++;
	}
	send_zero(pid);
	return (0);
}
