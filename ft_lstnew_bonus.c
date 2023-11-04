/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:17:27 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:18:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstnew() function allocates (with malloc(3)) and returns a new
 * element. The variable 'content' is initialized with the value of the
 * parameter 'content'. The variable 'next' is initialized to NULL.
 *
 * @param	{void*}		content	The content to create the new element with.
 *
 * @returns	{t_list*}			The new element.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*list_item;

	list_item = (t_list *)malloc(sizeof(t_list));
	if (list_item != NULL)
	{
		list_item->content = content;
		list_item->next = NULL;
	}
	return (list_item);
}
