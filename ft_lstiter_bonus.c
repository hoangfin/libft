/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:16:44 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:21:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstiter() function iterates the list 'lst' and applies the function
 * 'f' to the content of each element.
 *
 * @param	{t_list*}			lst		The adress of a pointer to an element.
 * @param	{void(*)(void*)}	f		The adress of the function used to
 * 										iterate on the list.
 *
 * @returns	{void}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
