#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"
#include <unistd.h>

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
	static union u_chr	c;
	static int			counter;
	static char			*ptr;

	initialize_ptr(&ptr);
	if (signal == ZERO)
		set_bit(&c, 0, counter);
	else if (signal == ONE)
		set_bit(&c, 1, counter);
	if (counter == 7)
	{
		counter = 0;
		concatenate_byte(&ptr, (unsigned char)c.chr);
		check_end_of_string(&ptr, (unsigned char)c.chr);
	}
	else
		counter++;
}

void	signal_handler(int num, siginfo_t *info, void *ctx)
{
	build_string(num);
	usleep(100);
	kill(info->si_pid, SIGUSR2);
	usleep(100);
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (true)
		pause();
	return (0);
}
