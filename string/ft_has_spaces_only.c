/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_spaces_only.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:43:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/17 16:47:32 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

t_bool	ft_has_spaces_only(const char *str)
{
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}
