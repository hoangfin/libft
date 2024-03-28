/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:15:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/28 10:19:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

/**
 * This function will delete the specified strings array and set it to NULL.
 *
 * @param	{char***} p_array The address of strings array.
 * @returns	{void}
*/
void	ft_delete_string_array(char ***p_array)
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
