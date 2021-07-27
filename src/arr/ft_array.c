/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_array.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/29 10:36:21 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/07/27 16:26:37 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_array.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

t_voidp_arr	*new_voidp_arr(size_t size)
{
	t_voidp_arr	*arr;

	if (size == 0)
		size = DEFAULT_ARR_SIZE;
	arr = malloc(sizeof(t_voidp_arr));
	if (arr == NULL)
		return (NULL);
	arr->content = malloc(size * sizeof(void *));
	if (arr->content == NULL)
	{
		free(arr);
		return (NULL);
	}
	arr->size = size;
	arr->length = 0;
	return (arr);
}

void	destroy_arr(t_voidp_arr *arr)
{
	free(arr->content);
	free(arr);
}

t_voidp_arr	*set(t_voidp_arr *arr, size_t index, void *value)
{
	if (extend_until(arr, index + 1) == NULL)
		return (NULL);
	arr->content[index] = value;
	if (arr->length <= index)
		arr->length = index + 1;
	return (arr);
}

void	*get(t_voidp_arr *arr, size_t index)
{
	if (index >= arr->length)
		return (NULL);
	return (arr->content[index]);
}

char	*stringify(t_voidp_arr *arr)
{
	char	*str;
	char	*str2;
	void	*value;
	size_t	i;

	if (arr->length == 0)
		return ("[ ]");
	const int len = 6;
	str = malloc((len + 2) * arr->length + 2);
	str2 = malloc((len + 2) * arr->length + 2);
	ft_memcpy(str, "[ ", 3);
	i = 0;
	while (i < arr->length - 1)
	{
		value = get(arr, i);
		sprintf(str2, "%s%.*li, ", str, len, (unsigned long)value);
		ft_memcpy(str, str2, (len + 2) * arr->length + 2);
		i++;
	}
	value = get(arr, i);
	sprintf(str2, "%s%.*li ]", str, len, (unsigned long)value);
	free(str);
	return (str2);
}

void	print(t_voidp_arr *arr)
{
	char	*str;

	str = stringify(arr);
	printf("%s\n", str);
}

int main(void)
{
	// new_voidp_arr
	if (1) {
		ASSERT_UNEQUAL(new_voidp_arr(0), NULL);
		ASSERT_UNEQUAL(new_voidp_arr(0)->content, NULL);
		ASSERT_EQUAL(new_voidp_arr(0)->size, DEFAULT_ARR_SIZE);
		ASSERT_EQUAL(new_voidp_arr(0)->length, 0);

		ASSERT_UNEQUAL(new_voidp_arr(1), NULL);
		ASSERT_UNEQUAL(new_voidp_arr(1)->content, NULL);
		ASSERT_EQUAL(new_voidp_arr(1)->size, 1);
		ASSERT_EQUAL(new_voidp_arr(1)->length, 0);

		ASSERT_UNEQUAL(new_voidp_arr(12), NULL);
		ASSERT_UNEQUAL(new_voidp_arr(12)->content, NULL);
		ASSERT_EQUAL(new_voidp_arr(12)->size, 12);
		ASSERT_EQUAL(new_voidp_arr(12)->length, 0);
	}

	// extend
	if (0) {
		// NULL
		if (0) {
			ASSERT_UNEQUAL(extend(NULL, 0), NULL);
			ASSERT_EQUAL(extend(NULL, 0)->size, DEFAULT_ARR_SIZE);
			ASSERT_UNEQUAL(extend(NULL, 0)->content, NULL);

			ASSERT_UNEQUAL(extend(NULL, 1), NULL);
			ASSERT_EQUAL(extend(NULL, 1)->size, 1);
			ASSERT_UNEQUAL(extend(NULL, 1)->content, NULL);

			ASSERT_UNEQUAL(extend(NULL, 12), NULL);
			ASSERT_EQUAL(extend(NULL, 12)->size, 12);
			ASSERT_UNEQUAL(extend(NULL, 12)->content, NULL);
		}

		// !NULL
		if (1) {
			t_voidp_arr	*arr = new_voidp_arr(1);
			ASSERT_EQUAL(extend(arr, 0), NULL);

			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_UNEQUAL(extend(arr, 1), NULL);
			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_EQUAL(extend(arr, 1), arr);
			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_EQUAL(extend(arr, 1)->size, 1);
			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_UNEQUAL(extend(arr, 1)->content, NULL);

			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_UNEQUAL(extend(arr, 12), NULL);
			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_EQUAL(extend(arr, 12), arr);
			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_EQUAL(extend(arr, 12)->size, 12);
			destroy_arr(arr);
			arr = new_voidp_arr(1);
			ASSERT_UNEQUAL(extend(arr, 12)->content, NULL);
		}
	}

	if (1) {
		t_voidp_arr	*arr;

		arr = new_voidp_arr(4);
		print(arr);
		LOG(arr, push(arr, (void *)12), 0);
		LOG(arr, push(arr, (void *)235), 0);
		LOG(arr, push(arr, (void *)3278), 0);
		LOG(arr, push(arr, (void *)2), 0);
		LOG(arr, shift(arr, (void *)16), 0);
		LOG(arr, pop(arr), 1);
		LOG(arr, unshift(arr), 1);
	}
}
