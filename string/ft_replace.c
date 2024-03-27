/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:17:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/27 20:36:05 by hoatran          ###   ########.fr       */
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
void	ft_replace(char *str, const char *c_array, int c)
{
	int	i;

	if (str == NULL || *str == '\0' || c_array == NULL || *c_array == '\0')
		return ;
	while (*str != '\0')
	{
		i = 0;
		while (c_array[i] != '\0')
		{
			if (*str == c_array[i])
				*str = c;
			i++;
		}
		str++;
	}
}
