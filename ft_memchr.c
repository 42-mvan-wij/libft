/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:15:11 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 17:10:08 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ucs;
	unsigned char	ucc;
	void			*vs;

	ucs = (unsigned char *)s;
	ucc = c;
	vs = (void *)s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == ucc)
			return (vs + i);
		i++;
	}
	return (NULL);
}
