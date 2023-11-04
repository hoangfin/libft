/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:36:47 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/26 17:37:13 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strmapi() function applies the function 'f' to each
 * character of the string 's' to create a new string
 * (with malloc(3)) resulting from successive applications of 'f'.
 *
 * @param	{char*}	s		The string on which to iterate.
 * @param	{func}	f		The function to apply to each character.
 *
 * @returns	{char*}			The string created from the successive
 * 							applications of ’f’. Returns NULL if
 * 							the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str != NULL)
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
