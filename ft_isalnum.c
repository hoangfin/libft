/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:46:54 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:50:55 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_isalnum function checks whether the integer c is a digit or an
 * alphabet character.
 *
 * @param	{int}	c		Integer value to check for digit and alphabet.
 * @returns	{int}	0		means neither c is an alphabet nor digit character.
 * 					1		means c is an alphabet or digit character.
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
