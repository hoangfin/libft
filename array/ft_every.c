/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_every.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:52:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/27 20:21:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

t_bool	ft_every(
	void *array,
	size_t element_size,
	size_t element_count,
	t_bool (*predicate)(void *, size_t, void *)
)
{
	size_t	i;
	void	*element_ptr;

	i = 0;
	if (array == NULL || element_count == 0 || predicate == NULL)
		return (false);
	while (i < element_count)
	{
		element_ptr = (char *)array + i * element_size;
		if (predicate(element_ptr, i, array) == false)
			return (false);
		i++;
	}
	return (true);
}
