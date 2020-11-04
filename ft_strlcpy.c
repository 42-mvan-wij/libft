/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:24:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/11/03 16:01:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (srcsize < dstsize - 1)
		ft_memcpy(dst, src, (srcsize + 1) * sizeof(char));
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, (dstsize - 1) * sizeof(char));
		dst[dstsize - 1] = '\0';
	}
	return (srcsize);
}
