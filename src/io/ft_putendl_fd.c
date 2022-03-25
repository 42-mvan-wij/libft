/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:34:35 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/03/25 15:48:26 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * Prints @p s to @p fd and appends a newline
 * @param s string
 * @param fd file descriptor
 * @returns
 */
ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	count;
	ssize_t	count2;

	count = ft_putstr_fd(s, fd);
	if (count < 0)
		return (count);
	count2 = ft_putchar_fd('\n', fd);
	if (count2 < 0)
		return (count2);
	return (count + count2);
}
