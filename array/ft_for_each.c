/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_each.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:42:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/27 20:20:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

void	ft_for_each(
	void *array,
	size_t element_size,
	size_t element_count,
	void (*callback)(void *, size_t, void *)
)
{
	size_t	i;
	void	*element_ptr;

	if (array == NULL || element_count == 0 || callback == NULL)
		return ;
	i = 0;
	while (i < element_count)
	{
		element_ptr = (char *)array + i * element_size;
		callback(element_ptr, i, array);
		i++;
	}
}
