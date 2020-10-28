/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:15:05 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/28 15:20:17 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isspace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
