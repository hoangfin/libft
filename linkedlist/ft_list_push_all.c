/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:53:49 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/22 18:22:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

int	ft_list_push_all(t_list *dest, t_list *src, void *(*copy)(void *))
{
	size_t	i;
	t_node	*node;
	void	*data;

	i = 0;
	node = src->head;
	while (i < src->length)
	{
		if (copy != NULL)
		{
			data = copy(node->data);
			if (data == NULL)
				return (-1);
			if (ft_list_push(dest, data) < 0)
				return (-1);
		}
		else
		{
			if (ft_list_push(dest, node->data) < 0)
				return (-1);
		}
		node = node->next;
		i++;
	}
	return (0);
}
