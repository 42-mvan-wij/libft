/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:24:08 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 18:33:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	int max;
	int i;

	max = ft_strlen(src);
	i = 0;
	while (i < max && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == dstsize && i < max + 1)
		dst[i] = '\0';
	return (max);
}
