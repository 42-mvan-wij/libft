/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atodl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 00:37:09 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/09/19 14:36:12 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	int_part(char **str, long double *res)
{
	*res = 0;
	while (ft_isdigit(**str))
	{
		*res *= 10;
		*res += (**str - '0');
		(*str)++;
	}
}

static void	float_part(char **str, long double *res)
{
	long double	divider;

	if (**str != '.')
		return ;
	(*str)++;
	divider = 1;
	while (ft_isdigit(**str))
	{
		divider *= 10;
		*res += ((long double)(**str - '0')) / divider;
		(*str)++;
	}
}

/**
 * Converts @p str to a long double
 * @param str
 * @return
 */
long double	ft_atodl(char *str)
{
	bool		is_neg;
	long double	res;

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
