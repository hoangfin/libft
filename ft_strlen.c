/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:14:28 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:15:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strlen() function calculates the length of the string pointed
 * to by s, excluding the NULL-terminated byte ('\0').
 *
 * @param	{char*}	s	The string pointed to by s.
 *
 * @returns	{size_t}	The number of bytes in s.
*/
size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
