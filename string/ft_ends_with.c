/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:42:48 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:29:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_ends_with(const char *string, const char *search_string)
{
	size_t		ss_length;
	size_t		string_length;
	const char	*temp;

	ss_length = ft_strlen(search_string);
	if (ss_length == 0)
		return (1);
	string_length = ft_strlen(string);
	if (ss_length > string_length)
		return (0);
	temp = string + string_length - ss_length;
	while (*temp != '\0' && *search_string != '\0')
	{
		if (*temp != *search_string)
			return (0);
		temp++;
		search_string++;
	}
	return (1);
}
