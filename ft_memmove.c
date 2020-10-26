/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:11:27 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 18:14:52 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
