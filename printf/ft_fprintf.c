/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:30:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/07 18:20:22 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_format(
	int fd,
	char const **format,
	va_list args,
	t_print_service *ps
)
{
	const char		*sup_cvs = SUP_CONVERSIONS;
	const char		*conversion = NULL;
	const char		*temp;
	t_print_format	print_format;
	int				count;

	(*format)++;
	temp = *format;
	while (*temp != '\0')
	{
		conversion = ft_strchr(sup_cvs, *temp);
		if (conversion != NULL)
			break ;
		temp++;
	}
	if (conversion == NULL)
		return (write(fd, (*format)++, 1));
	print_format.conversion = *conversion;
	parse(fd, *format, &print_format, args);
	if (print_format.is_malformed)
		return (write(fd, (*format)++, 1));
	else
		count = ps[(int)*conversion](print_format, args);
	*format = ft_strchr(*format, *conversion) + 1;
	return (count);
}

static int	print(
	int fd,
	const char **format,
	va_list args,
	t_print_service *ps
)
{
	int			printed_chars_count;
	int			count;
	const char	*percent_sign;

	if (**format == '\0')
		return (0);
	percent_sign = ft_strchr(*format, '%');
	if (percent_sign == NULL)
		return (write(fd, *format, ft_strlen(*format)));
	count = 0;
	printed_chars_count = write(fd, *format, percent_sign - *format);
	if (printed_chars_count < 0)
		return (-1);
	count += printed_chars_count;
	*format = percent_sign;
	printed_chars_count = print_format(fd, format, args, ps);
	if (printed_chars_count < 0)
		return (-1);
	count += printed_chars_count;
	printed_chars_count = print(fd, format, args, ps);
	if (printed_chars_count < 0)
		return (-1);
	count += printed_chars_count;
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	t_print_service	print_services[128];
	va_list			args;
	int				count;

	print_services['c'] = print_c;
	print_services['s'] = print_s;
	print_services['p'] = print_p;
	print_services['d'] = print_d;
	print_services['i'] = print_d;
	print_services['u'] = print_u;
	print_services['x'] = print_x;
	print_services['X'] = print_x;
	print_services['%'] = print_percent;
	va_start(args, format);
	count = print(fd, &format, args, print_services);
	va_end(args);
	return (count);
}
