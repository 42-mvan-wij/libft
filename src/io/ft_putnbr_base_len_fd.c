/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_len_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:09:02 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/07/21 12:20:55 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static bool	accumulate(ssize_t *count, ssize_t add)
{
	*count += add;
	return (add >= 0);
}

/**
 * Prints @p nbr in @p base to @p fd
 * @param nbr number
 * @param basechars characters to choose from
 * @param base base to use
 * @param fd file descriptor
 * @returns
 */
ssize_t	ft_putnbr_base_len_fd(long long n, char *basechars, int base, int fd)
{
	ssize_t	count;
	bool	was_ok;

	count = 0;
	if (n >= 0)
	{
		was_ok = true;
		if (n / base != 0)
			was_ok = accumulate(&count,
					ft_putnbr_base_len_fd(n / base, basechars, base, fd));
		if (was_ok)
			was_ok = accumulate(&count, ft_putchar_fd(basechars[n % base], fd));
	}
	else
	{
		was_ok = accumulate(&count, ft_putchar_fd('-', fd));
		if (was_ok && n / base != 0)
			was_ok = accumulate(&count,
					ft_putnbr_base_len_fd(-(n / base), basechars, base, fd));
		if (was_ok)
			was_ok = ft_putchar_fd(basechars[-(n % base)], fd);
	}
	if (was_ok)
		return (count);
	return (-1);
}
