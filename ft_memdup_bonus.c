/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 12:51:32 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/11/25 12:56:49 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_memdup(const void *ptr, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		((char *)dst)[size] = ((char *)ptr)[size];
	}
	return (dst);
}
