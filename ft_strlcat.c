/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:24:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 18:44:31 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	int init_dstsize;
	int srcsize;
	int i;

	init_dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	i = 0;
	while (i < srcsize && i + init_dstsize < dstsize - 1)
	{
		dst[init_dstsize + i] = src[i];
		i++;
	}
	if (dstsize > 0 || init_dstsize >= dstsize)
		dst[i] = '\0';
	return (init_dstsize + srclen);
}
