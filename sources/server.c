#include "minitalk.h"

void	msg_handler(int num)
{
	ft_putstr_fd("Signal received!\n", 1);
	(void)num;
}

int main(void)
{
	signal(SIGUSR1, msg_handler);
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);

	while (true)
		sleep(1);
}
