#include "ft_printf.h"
#include "minitalk.h"

static int	g_lock;

void	response_handler(int sig)
{
	(void)sig;
	g_lock = 0;
}

void	send_bit(int pid, int bit)
{
	if (!bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	g_lock = 1;
}

void	send_zero(int pid)
{
	int	i;
	int	byte;

	i = 0;
	byte = 0;
	while (i < 8)
	{
		send_bit(pid, (byte >> i) & 0x01);
		while (g_lock == 1)
			usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*str;

	if (argc != 3)
		exit(1);
	pid = ft_atoi(*(argv + 1));
	str = (*(argv + 2));
	signal(SIGUSR1, &response_handler);
	signal(SIGUSR2, &response_handler);
	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			send_bit(pid, (*str >> i) & 0x01);
			while (g_lock == 1)
				usleep(200);
			i++;
		}
		str++;
	}
	send_zero(pid);
}
