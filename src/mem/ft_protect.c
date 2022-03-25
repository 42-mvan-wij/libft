/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_protect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By:                                              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 17:09:17 by rvan-duy      #+#    #+#                 */
/*   Updated: 2022/03/25 11:58:05 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	*ft_protect(void *ptr)
{
	if (ptr != NULL)
		return (ptr);
	ft_putstr_fd("Malloc failed\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
	return (NULL);
}
