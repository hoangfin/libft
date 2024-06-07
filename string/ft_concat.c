/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:13:01 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/07 22:22:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_concat(char **target, int string_count, ...)
{
	const char	*temp = *target;
	va_list		args;
	char		*str;

	va_start(args, string_count);
	str = ft_join_strings(string_count, args);
	va_end(args);
	if (str == NULL)
		return (-1);
	if (*target == NULL)
		*target = str;
	else
		*target = ft_strjoin(*target, str);
	free(str);
	if (*target == NULL)
	{
		*target = (char *)temp;
		return (-1);
	}
	free((void *)temp);
	return (0);
}