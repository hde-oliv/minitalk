#include "minitalk.h"
#include <stdio.h>

#define ZERO 10
#define ONE 12

static int counter;

void	set_bit(union u_chr *c, int i, int bit)
{
	if (bit == 1)
		c->bits.a = i;
	else if (bit == 2)
		c->bits.b = i;
	else if (bit == 3)
		c->bits.c = i;
	else if (bit == 4)
		c->bits.d = i;
	else if (bit == 5)
		c->bits.e = i;
	else if (bit == 6)
		c->bits.f = i;
	else if (bit == 7)
		c->bits.g = i;
	else if (bit == 8)
		c->bits.h = i;
}

void	build_string(int signal)
{
	static char			array[40];
	static int			i;
	static union u_chr	c;

	(void)array;
	(void)i;
	if (counter != 8)
	{
		if (signal == ZERO)
			set_bit(&c, 0, counter);
		else if (signal == ONE)
			set_bit(&c, 1, counter);
		counter++;
	}
	else if (counter == 8)
	{
		if (signal == ZERO)
			set_bit(&c, 0, counter);
		else if (signal == ONE)
			set_bit(&c, 1, counter);
		counter = 0;
		printf(
			"#######\n"
			"c.a = %d\n"
			"c.b = %d\n"
			"c.c = %d\n"
			"c.d = %d\n"
			"c.e = %d\n"
			"c.f = %d\n"
			"c.g = %d\n"
			"c.h = %d\n"
			"#######\n",
			c.bits.a,
			c.bits.b,
			c.bits.c,
			c.bits.d,
			c.bits.e,
			c.bits.f,
			c.bits.g,
			c.bits.h);
	}
}

void	signal_handler(int num)
{
	build_string(num);
	kill(400, SIGUSR2);
	(void)num;
}

int main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (true)
		sleep(1);
}
