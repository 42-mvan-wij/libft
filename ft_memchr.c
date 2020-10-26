/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 18:15:11 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 18:17:33 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}
