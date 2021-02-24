/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/24 16:50:36 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/02/24 17:04:09 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(int nbr, int base)
{
	int		i;

	i = 1;
	if (nbr < 0)
		i++;
	while (nbr / base != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}
