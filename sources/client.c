#include "minitalk.h"

int main(int argc, char **argv)
{
	(void)argc;
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
	kill(ft_atoi(*(argv + 1)), SIGUSR2);
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
	kill(ft_atoi(*(argv + 1)), SIGUSR1);
}
