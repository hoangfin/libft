/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:27:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/14 17:03:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

static t_node	*ft_circular_list_pop(t_list *list)
{
	t_node	*detached_node;
	t_node	*new_tail_node;

	if (list->length == 0)
		return (NULL);
	detached_node = list->tail;
	new_tail_node = list->tail->prev;
	detached_node->next = NULL;
	detached_node->prev = NULL;
	if (list->length == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		new_tail_node->next = list->head;
		list->head->prev = new_tail_node;
		list->tail = new_tail_node;
	}
	list->length--;
	return (detached_node);
}

static t_node	*ft_linear_list_pop(t_list *list)
{
	t_node	*detached_node;
	t_node	*new_tail_node;

	if (list->length == 0)
		return (NULL);
	detached_node = list->tail;
	new_tail_node = list->tail->prev;
	detached_node->next = NULL;
	detached_node->prev = NULL;
	if (list->length == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		new_tail_node->next = NULL;
		list->tail = new_tail_node;
	}
	list->length--;
	return (detached_node);
}

/**
 * The ft_list_pop() function removes the last node from a linked list
 * and returns that removed node.
 *
 * This function changes the length of the linked list.
 *
 * @returns {t_node} node The node that has been removed from the linked list.
*/

t_node	*ft_list_pop(t_list *list)
{
	if (list->is_circular)
		return (ft_circular_list_pop(list));
	return (ft_linear_list_pop(list));
}
