/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_every.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:57:20 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:28:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_every(t_list *list, int (*pred)(void *, size_t, t_list *))
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = list->head;
	while (i < list->length)
	{
		if (pred(node->data, i, list) == 0)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
