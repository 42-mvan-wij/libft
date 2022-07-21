/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:39:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/07/21 12:20:48 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdbool.h>

static bool	accumulate(ssize_t *count, ssize_t add)
{
	*count += add;
	return (add >= 0);
}

/**
 * Prints @p n in base 10 to @p fd
 * @param n number
 * @param fd file descriptor
 * @returns
 */
ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	count;
	bool	was_ok;

	count = 0;
	if (n >= 0)
	{
		was_ok = true;
		if (n / 10 != 0)
			was_ok = accumulate(&count, ft_putnbr_fd(n / 10, fd));
		if (was_ok)
			was_ok = accumulate(&count, ft_putchar_fd('0' + (n % 10), fd));
	}
	else
	{
		was_ok = accumulate(&count, ft_putchar_fd('-', fd));
		if (was_ok && n / 10 != 0)
			was_ok = accumulate(&count, ft_putnbr_fd(-(n / 10), fd));
		if (was_ok)
			was_ok = ft_putchar_fd('0' - (n % 10), fd);
	}
	if (was_ok)
		return (count);
	return (-1);
}
