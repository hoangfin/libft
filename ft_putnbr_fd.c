/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:15:04 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/24 12:15:22 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_putnbr_fd function outputs the integer n to the file descriptor fd.
 *
 * @param	{int}	n	The integer to output.
 * @param	{int}	fd	The file descriptor.
 * 
 * @returns	{void}
*/
void	ft_putnbr_fd(int n, int fd)
{
	long	positive_num;

	positive_num = n;
	if (n < 0)
	{
		positive_num = -positive_num;
		ft_putchar_fd('-', fd);
	}
	if (positive_num / 10 == 0)
	{
		ft_putchar_fd(positive_num % 10 + '0', fd);
		return ;
	}
	ft_putnbr_fd(positive_num / 10, fd);
	ft_putchar_fd(positive_num % 10 + '0', fd);
}
