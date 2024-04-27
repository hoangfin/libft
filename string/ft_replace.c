/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:17:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/28 02:17:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * The ft_replace() replaces all characters in an array with a specified
 * character.
 *
 * @param 	{string}	str
 * @param 	{char*}		c_array
 * @param 	{int}		c
 * @returns	{void}
 *
*/
void	ft_replace(char *str, size_t size, const char *chars, int c)
{
	size_t	str_idx;
	size_t	i;

	if (*str == '\0' || size == 0 || chars[0] == '\0')
		return ;
	str_idx = 0;
	while (str_idx < size)
	{
		i = 0;
		while (chars[i] != '\0')
		{
			if (str[str_idx] == chars[i])
				str[str_idx] = c;
			i++;
		}
		str_idx++;
	}
}
