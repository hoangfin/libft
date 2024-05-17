/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:25:17 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/17 23:45:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

static void	ft_circular_list_push(t_list *list, t_node *node)
{
	if (list->length == 0)
	{
		node->next = node;
		node->prev = node;
		list->head = node;
		list->tail = node;
		list->length++;
		return ;
	}
	list->tail->next = node;
	node->prev = list->tail;
	node->next = list->head;
	list->head->prev = node;
	list->tail = node;
	list->length++;
}

static void	ft_linear_list_push(t_list *list, t_node *node)
{
	if (list->length == 0)
	{
		list->head = node;
		list->tail = node;
		list->length++;
		return ;
	}
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
	list->length++;
}

int	ft_list_push(t_list *list, void *data)
{
	t_node	*node;

	node = ft_list_node(data);
	if (node == NULL)
		return (-1);
	if (list->is_circular)
		ft_circular_list_push(list, node);
	else
		ft_linear_list_push(list, node);
	return (0);
}
