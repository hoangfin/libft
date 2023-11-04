/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:14:20 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:15:01 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstadd_front() function adds the element 'new' at the beginning of the
 * list.
 *
 * @param	{t_list**}	lst		The address of a pointer to the first link of a
 * 								list.
 * @param	{t_list*}	new		The address of a pointer to the element to be
 * 								added to the list.
 *
 * @returns	{void}
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}
