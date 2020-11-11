/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 13:09:51 by mvan-wij      #+#    #+#                 */
/*   Updated: 2020/11/11 13:57:19 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((*lst)->next != NULL)
		ft_lstclear(&(*lst)->next, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
