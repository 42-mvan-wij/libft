/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:25:07 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/01 12:32:34 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "libft.h"

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
