/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 13:59:59 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/06/22 14:18:17 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

# define DEFAULT_ARR_SIZE 128

typedef struct s_voidp_arr {
	void	**content;
	size_t	size;
	size_t	length;
}	t_voidp_arr;

t_voidp_arr	*push(t_voidp_arr *arr, void *value);
void		*pop(t_voidp_arr *arr);
t_voidp_arr	*shift(t_voidp_arr *arr, void *value);
void		*unshift(t_voidp_arr *arr);
t_voidp_arr	*concat(t_voidp_arr *arr0, t_voidp_arr *arr1);
t_voidp_arr	*new_voidp_arr(size_t size);
void		destroy_arr(t_voidp_arr *arr);
t_voidp_arr	*set(t_voidp_arr *arr, size_t index, void *value);
void		*get(t_voidp_arr *arr, size_t index);

#endif
