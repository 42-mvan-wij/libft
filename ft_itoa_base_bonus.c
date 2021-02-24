/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 10:43:04 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 16:50:32 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(int nbr, char *basechars)
{
	int		base;
	int		i;
	int		is_neg;
	char	*res;

	if (basechars == NULL)
		return (NULL);
	base = ft_strlen(basechars);
	if (base < 2)
		return (NULL);
	is_neg = nbr < 0;
	i = ft_nbrlen(nbr, base);
	res = ft_calloc(i + 1, sizeof(char));
	while (i != is_neg)
	{
		i--;
		if (is_neg)
			res[i] = basechars[-nbr % base];
		else
			res[i] = basechars[nbr % base];
		nbr /= base;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}
