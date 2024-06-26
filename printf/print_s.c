/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/06 22:20:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_left(char *buf, t_print_format pf)
{
	if (write(pf.fd, buf, pf.precision) < 0)
		return (-1);
	if (pf.width < pf.precision)
		return (pf.precision);
	if (ft_putstrchr_fd(' ', pf.width - pf.precision, pf.fd) < 0)
		return (-1);
	return (pf.width);
}

static int	print_str(const char *buf, t_print_format pf)
{
	if (pf.width > pf.precision)
	{
		if (ft_putstrchr_fd(' ', pf.width - pf.precision, pf.fd) < 0)
			return (-1);
		if (write(pf.fd, buf, pf.precision) < 0)
			return (-1);
		return (pf.width);
	}
	return (write(pf.fd, buf, pf.precision));
}

int	print_s(t_print_format pf, va_list args)
{
	char	*str;
	size_t	str_len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	if (pf.has_period && pf.precision == -1)
		return (ft_putstrchr_fd(' ', pf.width, pf.fd));
	if (pf.precision == -1 || pf.precision > (int)str_len)
		pf.precision = (int)str_len;
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
		return (print_left(str, pf));
	return (print_str(str, pf));
}
