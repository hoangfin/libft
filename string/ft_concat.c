/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:13:01 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/22 20:18:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_concat(char **target, const char *str)
{
	char	*temp;

	if (*target == NULL)
	{
		*target = ft_strdup(str);
		if (*target == NULL)
			return (-1);
		return (0);
	}
	temp = *target;
	*target = ft_strjoin(*target, str);
	if (*target == NULL)
	{
		*target = temp;
		return (-1);
	}
	free(temp);
	return (0);
}