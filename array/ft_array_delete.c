/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:17:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/31 22:31:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

/**
 * @param {void **} arr_ptr Address of array
 * @param {size_t} length The number of elements in array.
 * @param {size_t} element_size The size of individual element in array.
 * @param {void (*)(void *)} delete The function pointer for deletion.
*/
void	ft_array_delete(
	void **arr_ptr,
	size_t element_size,
	size_t element_count,
	void (*delete)(void *)
)
{
	size_t	i;
	void	*element;

	i = 0;
	while (i < element_count)
	{
		element = (char *)(*arr_ptr) + i * element_size;
        if (delete) {
            delete(*(void **)element);
        }
		i++;
	}
	free(*arr_ptr);
	*arr_ptr = NULL;
}
