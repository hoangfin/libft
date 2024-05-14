/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:43:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/14 20:53:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_remove(
	t_list *list,
	void *data,
	t_bool (*pred)(t_node *, void *),
	void (*delete)(void *)
)
{
	t_node	*matched_node;
	t_node	*prev_node;
	t_node	*next_node;

	matched_node = ft_list_find(list, data, pred);
	if (matched_node == NULL)
		return ;
	if (matched_node == list->head)
		ft_list_shift(list);
	else if (matched_node == list->tail)
		ft_list_pop(list);
	else
	{
		prev_node = matched_node->prev;
		next_node = matched_node->next;
		matched_node->next = NULL;
		matched_node->prev = NULL;
		prev_node->next = next_node;
		next_node->prev = prev_node;
		list->length--;
	}
	if (delete != NULL)
		delete(matched_node->data);
	free(matched_node);
	return ;
}
