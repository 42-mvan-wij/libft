/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 00:37:09 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/09/19 14:39:14 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	int_part(char **str, double *res)
{
	*res = 0;
	while (ft_isdigit(**str))
	{
		*res *= 10;
		*res += (**str - '0');
		(*str)++;
	}
}

static void	float_part(char **str, double *res)
{
	double	divider;

	if (**str != '.')
		return ;
	(*str)++;
	divider = 1;
	while (ft_isdigit(**str))
	{
		divider *= 10;
		*res += ((double)(**str - '0')) / divider;
		(*str)++;
	}
}

/**
 * Converts @p str to a double
 * @param str
 * @return
 */
double	ft_atod(char *str)
{
	bool	is_neg;
	double	res;

	while (ft_isspace(*str))
		str++;
	is_neg = (*str == '-');
	if (*str == '+' || is_neg)
		str++;
	int_part(&str, &res);
	float_part(&str, &res);
	if (is_neg)
		return (-res);
	return (res);
}
