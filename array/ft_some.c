/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_some.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:29:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:26:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

int	ft_some(t_array *array, int (*pred)(void *, size_t, t_array *))
{
	size_t	i;
	char	*element;

	i = 0;
	if (pred == NULL)
		return (0);
	element = array->elements;
	while (i < array->length)
	{
		if (pred(element, i, array) == 1)
			return (1);
		element += array->e_size;
		i++;
	}
	return (0);
}
