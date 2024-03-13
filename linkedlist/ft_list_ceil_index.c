/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ceil_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:55:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/13 16:08:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_ceil_index(t_list *list, int number)
{
	size_t	i;
	int		index;
	t_node	*node;
	int		min;

	if (list->length == 0)
		return (-1);
	i = 0;
	index = -1;
	node = list->head;
	min = INT_MAX;
	while (i < list->length)
	{
		if (*((int *)node->data) >= number && *((int *)node->data) <= min)
		{
			min = *((int *)node->data);
			index = (int)i;
		}
		node = node->next;
		i++;
	}
	return (index);
}
