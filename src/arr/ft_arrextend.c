/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arrextend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 14:03:09 by mvan-wij      #+#    #+#                 */
/*   Updated: 2022/03/02 12:33:34 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include <stdlib.h>
#include <unistd.h>

t_voidp_arr	*extend(t_voidp_arr *arr, size_t new_size)
{
	void	*new;

	if (arr == NULL )
		return (NULL);
	if (new_size == arr->size)
		return (arr);
	if (new_size < arr->length || new_size == 0)
		return (NULL);
	new = malloc(new_size * sizeof(void *));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, arr->content, arr->length * sizeof(void *));
	free(arr->content);
	arr->content = new;
	arr->size = new_size;
	return (arr);
}

static t_voidp_arr	*extend_offset(t_voidp_arr *arr, size_t n_size, size_t off)
{
	void	**new;

	if (arr == NULL )
		return (NULL);
	if (n_size == arr->size && off == 0)
		return (arr);
	if (n_size < arr->length + off || n_size == 0)
		return (NULL);
	new = malloc(n_size * sizeof(void *));
	if (new == NULL)
		return (NULL);
	ft_memmove(new + off, arr->content, arr->length * sizeof(void *));
	free(arr->content);
	arr->content = new;
	arr->size = n_size;
	arr->length += off;
	return (arr);
}

t_voidp_arr	*extend_until(t_voidp_arr *arr, size_t min_size)
{
	while (arr->size < min_size)
	{
		if (extend(arr, arr->size * 2) == NULL)
			return (NULL);
	}
	return (arr);
}

t_voidp_arr	*extend_until_offset(t_voidp_arr *arr, size_t min_size, size_t off)
{
	if (arr->size < min_size || arr->size < arr->length + off)
	{
		if (extend_offset(arr, arr->size * 2, off) == NULL)
			return (NULL);
		while (arr->size < min_size || arr->size < arr->length + off)
		{
			if (extend(arr, arr->size * 2) == NULL)
				return (NULL);
		}
	}
	else
	{
		ft_memmove(
			arr->content + off,
			arr->content,
			arr->length * sizeof(void *));
		arr->length += off;
	}
	return (arr);
}
