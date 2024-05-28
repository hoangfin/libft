/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:26:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/27 16:43:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_list_clone(
	t_list *src,
	void *(*copy)(void *),
	void (*delete)(void *)
)
{
	t_list	*clone;
	t_node	*node;
	size_t	i;
	void	*data;

	clone = ft_list(src->is_circular);
	if (clone == NULL)
		return (NULL);
	i = 0;
	node = src->head;
	while (i < src->length)
	{
		data = copy(node->data);
		if (data == NULL)
		{
			ft_list_clear(&clone, delete);
			return (NULL);
		}
		ft_list_push(clone, data);
		node = node->next;
		i++;
	}
	return (clone);
}
