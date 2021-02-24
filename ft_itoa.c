/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:25:07 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 17:00:43 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		i;
	int		is_neg;
	char	*res;

	is_neg = nbr < 0;
	i = ft_nbrlen(nbr, 10);
	res = ft_calloc(i + 1, sizeof(char));
	while (i != is_neg)
	{
		i--;
		if (is_neg)
			res[i] = (-nbr % 10) + '0';
		else
			res[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (is_neg)
		res[0] = '-';
	return (res);
}
