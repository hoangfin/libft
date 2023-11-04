/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:28:03 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:21:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstmap() function iterates the list 'lst' and applies the
 * function 'f' to the content of each element. Creates a new list
 * resulting of the successive applications of the function 'f'.
 * The 'del' function is used to delete the content of an element if needed.
 *
 * @param	{t_list*}	lst		The adress of a pointer to an element.
 * @param	{function}	f		The adress of the function used to
 * 								iterate on the list.
 * @param	{function}	del		The adress of the function used to delete
 * 								the content of an element if needed.
 *
 * @returns	{t_list*}			The new list or NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_node;
	t_list	*node;

	head_node = NULL;
	node = NULL;
	while (lst != NULL)
	{
		if (f == NULL)
			node = ft_lstnew(lst->content);
		else
			node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		ft_lstadd_back(&head_node, node);
		lst = lst->next;
	}
	return (head_node);
}
