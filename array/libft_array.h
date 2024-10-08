/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:07:37 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:26:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

# include "../common/libft_common.h"

typedef struct s_array
{
	void	*elements;
	size_t	length;
	size_t	e_size;
	size_t	capacity;
}	t_array;

t_array	*ft_array(size_t e_size);
t_array	*ft_array_from(void *src_array, size_t length, size_t e_size);

void	ft_array_delete(\
			void *array, \
			size_t element_size, \
			size_t element_count, \
			void (*delete)(void *) \
		);

void	ft_for_each(\
			void *array, \
			size_t element_size, \
			size_t element_count, \
			void (*callback)(void *, size_t, void *) \
		);

int	ft_some(t_array *array, int (*pred)(void *, size_t, t_array *));

int	ft_every(\
			void *array, \
			size_t element_size, \
			size_t element_count, \
			int (*predicate)(void *, size_t, void *) \
		);

#endif