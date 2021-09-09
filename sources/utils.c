/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:40:19 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/29 17:06:00 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "minitalk.h"

void	initialize_ptr(char **ptr)
{
	if (!*ptr)
	{
		*ptr = (char *)ft_calloc(1, 1);
		if (*ptr == NULL)
			err(MALL_ERR);
	}
}

void	concatenate_byte(char **ptr, char c)
{
	int		size;
	char	*new;

	size = ft_strlen(*ptr) + 1;
	new = (char *)ft_calloc(size + 1, 1);
	if (new == NULL)
		err(MALL_ERR);
	ft_strlcpy(new, *ptr, size + 1);
	new[size - 1] = c;
	free(*ptr);
	*ptr = new;
}

void	check_end_of_string(char **ptr, char c)
{
	if (c == '\0')
	{
		ft_printf("%s\n", *ptr);
		free(*ptr);
		*ptr = NULL;
	}
}

void	err(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(1);
}
