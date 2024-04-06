/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:20:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/06 22:19:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_left(t_print_format pf)
{
	if (write(pf.fd, "%", 1) < 0)
		return (-1);
	if (pf.width <= 1)
		return (1);
	if (ft_putstrchr_fd(' ', pf.width - 1, pf.fd) < 0)
		return (-1);
	return (pf.width);
}

int	print_percent(t_print_format pf, va_list args)
{
	(void)args;
	pf.precision = 1;
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
		return (print_left(pf));
	if (pf.width > 1)
	{
		if (pf.flag & FT_PRINTF_FLAG_ZERO)
		{
			if (ft_putstrchr_fd('0', pf.width - 1, pf.fd) < 0)
				return (-1);
		}
		else
		{
			if (ft_putstrchr_fd(' ', pf.width - 1, pf.fd) < 0)
				return (-1);
		}
		if (write(pf.fd, "%", 1) < 0)
			return (-1);
		return (pf.width);
	}
	return (write(pf.fd, "%", 1));
}
