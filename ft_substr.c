/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:58:40 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 15:08:44 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_substr() function allocates and returns a substring from the string
 * 's'. The substring begins at index 'start' and is of maximum size 'len'.
 *
 * @param	{char*}		s		The string from which to create the substring.
 * @param	{int}		start	The start index in the string 's'.
 * @param	{size_t}	len		The maximum length of the substring.
 *
 * @returns	{char*}				The substring or NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (len == 0)
	{
		substr[0] = '\0';
		return (substr);
	}
	if (start >= ft_strlen(s))
		ft_strlcpy(substr, "", len + 1);
	else
		ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
