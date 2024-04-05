/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:15:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/05 21:15:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * This function will delete the specified strings array and set it to NULL.
 *
 * @param	{char***} p_array The address of strings array.
 * @returns	{void}
*/
void	ft_del_str_arr(char ***p_array)
{
	char	**p_string;

	if (p_array == NULL)
		return ;
	p_string = *p_array;
	while (p_string != NULL && *p_string != NULL)
	{
		free(*p_string);
		p_string++;
	}
	free(*p_array);
	*p_array = NULL;
}
