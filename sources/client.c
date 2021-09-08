#include "minitalk.h"

void send_bit(int pid, int bit)
{
	if (!bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{
	int i = 0;
	int	pid;
	int	byte;
	char	*str;

	(void)argc;
	pid = ft_atoi(*(argv + 1));
	str = (*(argv + 2));
	while (*str)
	{
		byte = *str;
		i = 0;
		while (i < 8)
		{
			send_bit(pid, (byte >> i) & 0x01);
			ft_putnbr_fd((byte >> i) & 0x01, 1);
			usleep(1000);
			i++;
		}
		str++;
	}
	byte = 0;
	i = 0;
	while (i < 8)
	{
		send_bit(pid, (byte >> i) & 0x01);
		ft_putnbr_fd((byte >> i) & 0x01, 1);
		usleep(1000);
		i++;
	}
}
