/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:00:49 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 15:03:51 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
