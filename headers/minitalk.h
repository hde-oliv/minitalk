#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf.h"
# include "libft.h"

# define ZERO 10
# define ONE 12

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

void	initialize_ptr(char **ptr);
void	concatenate_byte(char **ptr, char c);
void	check_end_of_string(char **ptr, char c);

#endif
