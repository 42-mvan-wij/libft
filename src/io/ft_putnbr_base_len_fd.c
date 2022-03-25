/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_len_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:09:02 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/03/25 16:02:32 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * Prints @p nbr in a base to @p fd
 * , base is defined by the length of @p basechars
 * @param nbr number
 * @param basechars characters to choose from (length defines base)
 * @param base base to use
 * @param fd file descriptor
 * @returns
 */
ssize_t	ft_putnbr_base_len_fd(long long n, char *basechars, int base, int fd)
{
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	if (n < 0)
	{
		count = ft_putchar_fd('-', fd);
		if (count < 0)
			return (count);
		tmp = ft_putchar_fd('0' - (n % base), fd);
	}
	else
		tmp = ft_putchar_fd('0' + (n % base), fd);
	if (tmp < 0)
		return (count);
	count += tmp;
	if (n < 0)
		tmp = ft_putnbr_base_len_fd(-(n / base), basechars, base, fd);
	else
		tmp = ft_putnbr_base_len_fd(n / base, basechars, base, fd);
	if (tmp < 0)
		return (tmp);
	return (count + tmp);
}
