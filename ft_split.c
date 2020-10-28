/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:59:22 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/28 20:02:16 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_splitcount(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		count--;
	return (count + 1);
}

static char	**ft_split_unsafe(char const *s, char c, char **arr)
{
	int i;
	int j;
	int start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] == c && (i != 0 && s[i - 1] != c))
		{
			arr[j] = ft_substr(s, start, i - start);
			j++;
		}
		i++;
	}
	if (s[i - 1] != c)
	{
		arr[j] = ft_substr(s, start, i - start);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	if (s == NULL)
		return (NULL);
	arr = malloc((ft_splitcount(s, c) + 1) * sizeof(char*));
	if (arr == NULL)
		return (NULL);
	return (ft_split_unsafe(s, c, arr));
}
