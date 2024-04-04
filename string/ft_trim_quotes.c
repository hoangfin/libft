/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 22:44:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/04 14:12:29 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_trim_quotes(char	*str)
{
	size_t	length;
	size_t	start;
	size_t	end;

	length = ft_strlen(str);
	if (length < 2)
		return ;
	start = 0;
	end = length - 1;
	if ((str[start] == 34 || str[start] == 39) && str[end] == str[start])
	{
		start++;
		end--;
	}
	if (start == 0)
		return ;
	if (start > end)
		*str = '\0';
	else
	{
		ft_memmove(str, str + start, end - start + 1);
		str[end - start + 1] = '\0';
	}
}
