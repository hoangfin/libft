/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:28:42 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/24 11:32:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_putchar_fd function outputs the char c to the file descriptor fd.
 *
 * @param	{char}	c	The character to output.
 * @param	{int}	fd	The file descriptor.
 *
 * @returns {void}
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
