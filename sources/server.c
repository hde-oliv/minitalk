#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

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
		ft_error("kill");
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
		ft_error("sigaction");
	if (sigaction(SIGUSR2, &sa, NULL))
		ft_error("sigaction");
	ft_printf("PID: %d\n", getpid());
	while (true)
		pause();
	return (0);
}
