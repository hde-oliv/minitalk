#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>

union u_chr
{
	struct
	{
		int	a:1;
		int	b:1;
		int	c:1;
		int	d:1;
		int	e:1;
		int	f:1;
		int	g:1;
		int	h:1;
	};
	char	chr;
};

/* utils */
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isspace(char c);
int		ft_isdigit(int c);

#endif
