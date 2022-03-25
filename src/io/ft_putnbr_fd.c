/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:39:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/03/25 15:56:41 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * Prints @p nbr in a base 10 to @p fd
 * @param nbr number
 * @param fd file descriptor
 * @returns
 */

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	count;
	ssize_t	tmp;

	count = 0;
	if (n < 0)
	{
		count = ft_putchar_fd('-', fd);
		if (count < 0)
			return (count);
		tmp = ft_putchar_fd('0' - (n % 10), fd);
	}
	else
		tmp = ft_putchar_fd('0' + (n % 10), fd);
	if (tmp < 0)
		return (count);
	count += tmp;
	if (n < 0)
		tmp = ft_putnbr_fd(-(n / 10), fd);
	else
		tmp = ft_putnbr_fd(n / 10, fd);
	if (tmp < 0)
		return (tmp);
	return (count + tmp);
}
