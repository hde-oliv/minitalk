#include "minitalk.h"
#include <stdio.h>

#define ZERO 10
#define ONE 12

static int counter;

void	set_bit(union u_chr *c, int i, int bit)
{
	if (bit == 0)
		c->a = i;
	else if (bit == 1)
		c->b = i;
	else if (bit == 2)
		c->c = i;
	else if (bit == 3)
		c->d = i;
	else if (bit == 4)
		c->e = i;
	else if (bit == 5)
		c->f = i;
	else if (bit == 6)
		c->g = i;
	else if (bit == 7)
		c->h = i;
}

void	build_string(int signal)
{
	static char			array[40];
	static int			i;
	static union u_chr	c;

	(void)array;
	(void)i;
	if (counter != 7)
	{
		if (signal == ZERO)
			set_bit(&c, 0, counter);
		else if (signal == ONE)
			set_bit(&c, 1, counter);
		counter++;
	}
	else if (counter == 7)
	{
		if (signal == ZERO)
			set_bit(&c, 0, counter);
		else if (signal == ONE)
			set_bit(&c, 1, counter);
		counter = 0;
		printf("\n\n%c\n\n", (unsigned char)c.chr);
	}
}

void	signal_handler(int num, siginfo_t *info, void *ctx)
{
	build_string(num);
	kill(info->si_pid, SIGUSR1);
	(void)ctx;
}

int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (true)
		pause();
}
