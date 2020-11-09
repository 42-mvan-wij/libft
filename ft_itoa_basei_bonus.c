/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_basei_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:11:59 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/11/08 12:10:25 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_basei(int nbr, int base)
{
	char	*basechars;
	int		i;
	char	*val;

	if (base < 2 || base > 36)
		return (NULL);
	basechars = malloc((base + 1) * sizeof(char));
	if (basechars == NULL)
		return (NULL);
	i = 0;
	while (i <= 9 && i < base)
	{
		basechars[i] = (char)('0' + i);
		i++;
	}
	while (i < base)
	{
		basechars[i] = (char)('a' + i - 10);
		i++;
	}
	basechars[i] = '\0';
	val = ft_itoa_base(nbr, basechars);
	free(basechars);
	return (val);
}
