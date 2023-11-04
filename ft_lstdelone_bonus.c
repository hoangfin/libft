/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:16:07 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:20:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstdelone() function takes as a parameter an element and
 * frees the memory of the element's content using the function 'del'
 * given as a parameter and free the element. The memory of 'next'
 * must not be freed.
 *
 * @param	{t_list*}	lst		The element to free.
 * @param	{function}	del		The address of the function used to delete the
 * 								content.
 *
 * @returns	{void}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
