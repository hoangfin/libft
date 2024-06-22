/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:57:43 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/22 11:08:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	*ft_list_to_array(t_list *list, size_t element_size)
{
	void	*array;
	void	*element;
	size_t	i;
	t_node	*node;

	array = ft_calloc(list->length + 1, element_size);
	if (array == NULL)
		return (NULL);
	i = 0;
	node = list->head;
	while (i < list->length)
	{
		element = (char *)array + i * element_size;
		*(void **)element = node->data;
		node = node->next;
		i++;
	}
	return (array);
}
