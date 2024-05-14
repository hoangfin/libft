/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:46:33 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/14 16:53:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/**
 * The ft_list_find() returns the first node in the provided list that satisfies
 * the provided testing function. If no values satisfy the testing function,
 * NULL is returned.
*/
t_node	*ft_list_find(
	t_list *list,
	void *data,
	t_bool (*pred)(t_node *, void *)
)
{
	size_t	i;
	t_node	*node;

	if (list->length == 0)
		return (NULL);
	i = 0;
	node = list->head;
	while (i < list->length)
	{
		if (pred(node, data))
			return (node);
		node = node->next;
		i++;
	}
	return (NULL);
}
