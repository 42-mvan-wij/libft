/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_and_nullify.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: marius <marius@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 20:38:11 by marius        #+#    #+#                 */
/*   Updated: 2021/09/26 20:38:11 by marius        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_free_and_nullify(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}