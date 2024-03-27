/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:15:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/27 22:25:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_del_str_array(char ***str_array)
{
	char	**current;

	if (str_array == NULL)
		return ;
	current = *str_array;
	while (current != NULL && *current != NULL)
	{
		free(*current);
		current++;
	}
	free(*str_array);
	*str_array = NULL;
}