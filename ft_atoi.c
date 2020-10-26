/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:33:52 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/10/26 14:56:04 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int offset;
	int result;

	offset = 0;
	result = 0;
	while (*(str + offset) >= '0' && *(str + offset) <= '9')
	{
		result *= 10;
		result += *(str + offset) - '0';
		offset++;
	}
	return (result);
}
