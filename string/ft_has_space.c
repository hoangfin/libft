/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:14:31 by hoatran           #+#    #+#             */
/*   Updated: 2024/05/20 22:16:16 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

t_bool	ft_has_space(const char *str)
{
	while (*str != '\0')
	{
		if (ft_isspace(*str))
			return (true);
		str++;
	}
	return (false);
}
