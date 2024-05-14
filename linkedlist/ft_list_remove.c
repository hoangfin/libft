/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:43:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/14 17:14:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_remove(t_list *list, int index, void (*delete)(void *))
{
	t_node	*detached_node;

	detached_node = NULL;
	if (list->length == 0 || index < 0)
		return ;
	if (index == 0)
		detached_node = ft_list_shift(list);
	else if (index == (int)list->length - 1)
		detached_node = ft_list_pop(list);
	// else
	// {
		// detached_node = ft_list_find_by_index(list, index);

	// }
	delete(detached_node->data);
	free(detached_node);
	return ;
}
