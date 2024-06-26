/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:08:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/24 16:14:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/**
 * The ft_linkedlist_foreach() function executes a provided function once for
 * each node of a linked list.
*/
void	ft_list_foreach(t_list *list, void (*fn)(t_node *, size_t))
{
	size_t	i;
	t_node	*node;

	if (list->length == 0)
		return ;
	i = 0;
	node = list->head;
	while (i < list->length)
	{
		fn(node, i);
		node = node->next;
		i++;
	}
}
