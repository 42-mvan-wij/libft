/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:46:34 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 17:49:00 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
	{
		b[len - 1] = (unsigned char)c;
		len--;
	}
}
