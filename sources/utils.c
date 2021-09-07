#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	res;

	minus = -1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		res = (res * 10) - (*str++ - '0');
	return (minus * res);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
