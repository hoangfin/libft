/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:41:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/06 22:13:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_c(t_print_format pf, va_list args)
{
	if (pf.width <= 1)
		return (ft_putchar_fd(va_arg(args, int), pf.fd));
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
	{
		if (ft_putchar_fd(va_arg(args, int), pf.fd) < 0)
			return (-1);
		if (ft_putstrchr_fd(' ', pf.width - 1, pf.fd) < 0)
			return (-1);
		return (pf.width);
	}
	if (ft_putstrchr_fd(' ', pf.width - 1, pf.fd) < 0)
		return (-1);
	if (ft_putchar_fd(va_arg(args, int), pf.fd) < 0)
		return (-1);
	return (pf.width);
}
