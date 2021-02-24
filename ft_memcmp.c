/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:17:55 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 17:11:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*cs1;
	char			*cs2;
	char			*ucs1;
	char			*ucs2;

	cs1 = s1;
	cs2 = s2;
	ucs1 = s1;
	ucs2 = s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (ucs1[i] - ucs2[i]);
		i++;
	}
	return (0);
}
