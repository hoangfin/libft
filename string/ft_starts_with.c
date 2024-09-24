/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starts_with.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:12:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:30:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_starts_with(const char *string, const char *search_string)
{
	size_t	string_len;
	size_t	search_string_len;
	size_t	i;

	if (*search_string == '\0')
		return (1);
	string_len = ft_strlen(string);
	search_string_len = ft_strlen(search_string);
	if (string_len < search_string_len)
		return (0);
	i = 0;
	while (i < search_string_len)
	{
		if (string[i] != search_string[i])
			return (0);
		i++;
	}
	return (1);
}
