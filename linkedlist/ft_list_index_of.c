/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_index_of.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:18:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:28:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_index_of(t_list *list, void *data, int (*pred)(t_node *, void *))
{
	int		i;
	t_node	*node;

	i = 0;
	node = list->head;
	while (i < (int)list->length)
	{
		if (pred(node, data))
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}
