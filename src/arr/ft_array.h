/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 14:18:19 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/27 16:11:54 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_INT_H
# define FT_ARRAY_INT_H

# include "libft_arr.h"
# include <stddef.h>

# define ASSERT(statement) { \
	if (!(statement)) \
		printf("Assert: (%s) returned false\n", #statement); \
}
# define ASSERT_EQUAL(a, b) { \
	if (a != b) \
		printf("Assert: %s != %s\n", #a, #b); \
}
# define ASSERT_UNEQUAL(a, b) { \
	if (a == b) \
		printf("Assert: %s == %s\n", #a, #b); \
}
# define LOG(arr, cmd, does_print) { \
	printf("\n%s: ", #cmd); \
	if (does_print) {\
		printf("\n\t%.6li", (unsigned long)cmd); \
	} \
	else { \
		cmd; \
	} \
	printf("\n\t"); \
	print(arr); \
}

t_voidp_arr	*extend(t_voidp_arr *arr, size_t new_size);
t_voidp_arr	*extend_until(t_voidp_arr *arr, size_t min_size);
t_voidp_arr	*extend_until_offset(t_voidp_arr *arr, size_t min_size, size_t off);

#endif
