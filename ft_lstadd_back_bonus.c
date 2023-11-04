/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:53:21 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 16:58:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstadd_back() function adds the element 'new' at the end of the list.
 *
 * @param	{t_list**}	lst		The address of a pointer to the first
 * 								link of a list.
 * @param	{t_list*}	new		The address of a data element (type
 * 								t_list) to be added to the list.
 *
 * @returns	{void}
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
