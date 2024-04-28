/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:02:17 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/28 13:05:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * The ft_trim() function removes the specified character from a string.
 *
 * @param {char*} str The target string
 * @param {int} c The character that will be removed from the string 'str'
*/
void	ft_trim(char *str, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}
