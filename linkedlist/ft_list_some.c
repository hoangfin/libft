/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_some.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:04:13 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:29:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_some(t_list *list, int (*pred)(void *, size_t, t_list *))
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = list->head;
	while (i < list->length)
	{
		if (pred(node->data, i, list) == 1)
			return (1);
		node = node->next;
		i++;
	}
	return (0);
}
