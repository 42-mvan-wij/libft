/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:24:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/11/03 14:58:33 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t init_dstsize;

	init_dstsize = ft_strlen(dst);
	if (init_dstsize > dstsize)
		return (dstsize + ft_strlen(src));
	return (init_dstsize + ft_strlcpy(dst + init_dstsize, src, dstsize));
}
