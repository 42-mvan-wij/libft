/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:36:48 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 17:20:44 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*cs;

	cc = c;
	cs = s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return (cs + i);
		i++;
	}
	if (c == '\0')
		return (cs + i);
	return (NULL);
}
