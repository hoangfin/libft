/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:14:46 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/24 14:17:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

/**
 * The ft_calloc() function contiguously allocates enough space for
 * an array of nmemb elements of size bytes each and returns
 * a pointer to the allocated memory. The allocated memory is
 * filled with bytes of value zero.
 *
 * @param	{size_t}	nmemb	The number of elements
 * @param	{size_t}	size	The size of each element in bytes.
 *
 * @returns	{void*}		A pointer to allocated memory.
 * 			NULL		If there is an error, errno to ENOMEM.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
