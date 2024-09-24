/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:14:31 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:29:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

int	ft_has_space(const char *str)
{
	while (*str != '\0')
	{
		if (ft_isspace(*str))
			return (1);
		str++;
	}
	return (0);
}
