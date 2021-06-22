/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arr_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 14:08:36 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/22 14:23:06 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array_int.h"
#include <stddef.h>
#include <unistd.h>

t_voidp_arr	*push(t_voidp_arr *arr, void *value)
{
	return (set(arr, arr->length, value));
}

void	*pop(t_voidp_arr *arr)
{
	void	*value;

	value = arr->content[arr->length - 1];
	arr->length--;
	return (value);
}

t_voidp_arr	*shift(t_voidp_arr *arr, void *value)
{
	if (extend_until_offset(arr, arr->length + 1, 1) == NULL)
		return (NULL);
	arr->content[0] = value;
	return (arr);
}

void	*unshift(t_voidp_arr *arr)
{
	void	*value;

	value = arr->content[0];
	ft_memmove(arr->content, arr->content + 1, arr->length * sizeof(void *));
	arr->length--;
	return (value);
}

t_voidp_arr	*concat(t_voidp_arr *arr0, t_voidp_arr *arr1)
{
	t_voidp_arr	*new_arr;

	new_arr = new_voidp_arr(arr0->length + arr1->length);
	ft_memmove(new_arr->content, arr0->content, arr0->length * sizeof(void *));
	ft_memmove(
		&new_arr->content[arr0->length],
		arr1->content,
		arr1->length * sizeof(void *));
	new_arr->length = arr0->length + arr1->length;
	return (new_arr);
}
