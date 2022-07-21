/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:09:02 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/07/21 12:14:03 by mvan-wij      ########   odam.nl         */
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
 * Prints @p nbr in a base to @p fd
 * , base is defined by the length of @p basechars
 * @param nbr number
 * @param basechars characters to choose from (length defines base)
 * @param fd file descriptor
 * @returns
 */
ssize_t	ft_putnbr_base_fd(long long n, char *basechars, int fd)
{
	return (ft_putnbr_base_len_fd(n, basechars, ft_strlen(basechars), fd));
}
