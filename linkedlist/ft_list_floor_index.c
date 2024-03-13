/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_floor_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:52:08 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/13 16:10:00 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_floor_index(t_list *list, int number)
{
	size_t	i;
	int		max;
	int		index;
	t_node	*node;

	if (list->length == 0)
		return (-1);
	i = 0;
	index = -1;
	node = list->head;
	max = INT_MIN;
	while (i < list->length)
	{
		if (*((int *)node->data) <= number && *((int *)node->data) >= max)
		{
			max = *((int *)node->data);
			index = (int)i;
		}
		node = node->next;
		i++;
	}
	return (index);
}
