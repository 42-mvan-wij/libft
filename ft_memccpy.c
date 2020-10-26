/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:51:10 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 18:29:02 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
