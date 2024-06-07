/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:23:08 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/07 22:50:20 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * Locates the first occurrence of the null-terminated
 * string `search` in the string `str`, where not more than n characters are
 * searched. Characters that appear after a `\0' character are not searched.
 *
 * @param str The string to search.
 * @param search The string to search in `str`.
 * @param n The number of searching bytes.
 *
 * @returns If `search` is an empty string, returns `str`. If `search` occurs
 * 			nowhere in `str`, returns NULL. Otherwise a pointer to the first
 * 			character of the first occurrence of `search` in `str` is returned.
*/
char	*ft_strnstr(const char *str, const char *search, size_t n)
{
	size_t	i;
	size_t	str_length;
	size_t	search_length;

	if (*search == '\0')
		return ((char *)str);
	if (n == 0)
		return (NULL);
	i = 0;
	str_length = ft_strlen(str);
	search_length = ft_strlen(search);
	if (str_length < search_length)
		return (NULL);
	while (i < n)
	{
		if (search_length > n - i)
			return (NULL);
		if (ft_strncmp(str + i, search, search_length) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
