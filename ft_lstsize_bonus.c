/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:18:13 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 17:18:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstsize() function counts the number of elements in a list.
 *
 * @param	{t_list*}	lst		The beginning of the list.
 *
 * @returns	{int}				The length of the list.
*/
int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	if (lst != NULL)
	{
		length++;
		while (lst->next != NULL)
		{
			lst = lst->next;
			length++;
		}
	}
	return (length);
}
