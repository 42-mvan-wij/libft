/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 12:32:15 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/03/25 15:49:02 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/**
 * Prints @p s to @p fd
 * @param s string
 * @param fd file descriptor
 * @returns
 */
ssize_t	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
