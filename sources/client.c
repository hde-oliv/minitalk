#include "minitalk.h"

void	send_next(int sig)
{
	(void)sig;
	write(1, "H", 1);
}

void send_bit(int pid, int bit)
{
	if (!bit)
		kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{
	int i = 0;
	int	pid;
	int	byte;

	signal(SIGUSR1, send_next);
	ft_putnbr_fd(getpid(), 1);
	(void)argc;
	pid = ft_atoi(*(argv + 1));
	byte = ft_atoi(*(argv + 2));
	while (i < 8)
	{
		send_bit(pid, (byte >> i) & 0x01);
		pause();
		i++;
	}
}
