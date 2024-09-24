/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_every.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:52:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:25:56 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

int	ft_every(
	void *array,
	size_t element_size,
	size_t element_count,
	int (*predicate)(void *, size_t, void *)
)
{
	size_t	i;
	void	*element_ptr;

	i = 0;
	if (array == NULL || element_count == 0 || predicate == NULL)
		return (0);
	while (i < element_count)
	{
		element_ptr = (char *)array + i * element_size;
		if (predicate(element_ptr, i, array) == 0)
			return (0);
		i++;
	}
	return (1);
}
