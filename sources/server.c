/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:19 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/29 17:06:00 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

void	set_bit(union u_chr *c, int i, int bit)
{
	if (bit == 0)
		c->byte.a = i;
	else if (bit == 1)
		c->byte.b = i;
	else if (bit == 2)
		c->byte.c = i;
	else if (bit == 3)
		c->byte.d = i;
	else if (bit == 4)
		c->byte.e = i;
	else if (bit == 5)
		c->byte.f = i;
	else if (bit == 6)
		c->byte.g = i;
	else if (bit == 7)
		c->byte.h = i;
}

void	signal_handler(int num, siginfo_t *info, void *ctx)
{
	static union u_chr	c;
	static int			counter;
	static char			*ptr;

	initialize_ptr(&ptr);
	if (num == ZERO)
		set_bit(&c, 0, counter);
	else if (num == ONE)
		set_bit(&c, 1, counter);
	if (counter == 7)
	{
		counter = 0;
		concatenate_byte(&ptr, (unsigned char)c.chr);
		check_end_of_string(&ptr, (unsigned char)c.chr);
	}
	else
		counter++;
	if (kill(info->si_pid, SIGUSR2))
		err(KILL_ERR);
	(void)ctx;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	sa.sa_mask = mask;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL))
		err(SIGA_ERR);
	if (sigaction(SIGUSR2, &sa, NULL))
		err(SIGA_ERR);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
