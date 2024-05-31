/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:17:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/31 21:01:23 by hoatran          ###   ########.fr       */
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
	char	*ptr;

	i = 0;
	ptr = (char *)(*arr_ptr);
	while (i < element_count)
	{
		if (delete != NULL)
			delete(ptr + i * element_size);
		i++;
	}
	free(*arr_ptr);
	*arr_ptr = NULL;
}
