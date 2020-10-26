/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:39:23 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 17:45:51 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;

	total = count * size
	mem = malloc(total);
	while (total > 0)
	{
		mem[total - 1] = '\0';
		total--;
	}
	return mem;
}
