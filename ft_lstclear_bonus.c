/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:15:09 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:20:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstclear() function deletes and frees the given element and every
 * successor of that element, using the function 'del' and free(3). Finally,
 * the pointer to the list must be set to NULL.
 *
 * @param	{t_list**}	lst		The adress of a pointer to an element.
 * @param	{function}	del		The adress of the function used to delete
 * 								the content of the element.
 *
 * @returns	{void}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
