/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_for_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:47:57 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/26 14:16:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/**
 * Executes the provided function once for each node of a linked list.
*/
int	ft_list_for_each(
	t_list *list,
	void *data,
	int (*fn)(t_node *, void *, size_t)
)
{
	size_t	i;
	t_node	*node;

	if (list->length == 0)
		return (0);
	i = 0;
	node = list->head;
	while (i < list->length)
	{
		if (fn(node, data, i) < 0)
			return (-1);
		node = node->next;
		i++;
	}
	return (0);
}
