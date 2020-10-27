/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:59:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/27 14:17:24 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrc(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	while (s[i] != '\0')
	{
		count += (s[i] == c);
		i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	arr = malloc(ft_chrc(s, c) * sizeof(char*));
	i = 0;
	j = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			arr[j] = ft_substr(s, start, i - start - 1);
			start = i + 1;
			j++;
		}
		i++;
	}
	return (arr);
}
