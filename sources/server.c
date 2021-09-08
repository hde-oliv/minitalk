#include "minitalk.h"
#include <stdio.h>
#include <string.h>

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

void	realloc_and_concatenate(char **ptr, int *size, int c)
{
	char *new;

	new = (char *)calloc(*size + 1, 1);
	strcpy(new, *ptr);
	new[*size - 1] = c;
	(*size)++;
	free(*ptr);
	*ptr = new;
}

void	build_string(int signal)
{
	static char			*ptr;
	static int			size;
	static union u_chr	c;

	if (!ptr)
		ptr = (char *) calloc(1, 1);
	if (!size)
		size = 1;
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
		if ((int)(unsigned char)c.chr == 0)
		{
			ft_putstr_fd(ptr, 1);
			ft_putchar_fd('\n', 1);
			free(ptr);
			ptr = (char *)calloc(1, 1);
			size = 1;
		}
		realloc_and_concatenate(&ptr, &size, (int)(unsigned char)c.chr);
		bzero(&c, sizeof(union u_chr));
	}
}

void	signal_handler(int num)
{
	build_string(num);
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
		pause();
}
