/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:20:35 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/04 19:05:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	convert(const char *num_str, char sign)
{
	long	number;

	number = 0;
	while (ft_isdigit(*num_str))
	{
		if (sign == '+')
		{
			if (number > LONG_MAX / 10)
				return (-1);
			number = number * 10;
			if (number > LONG_MAX - (*num_str - '0'))
				return (-1);
			number += (*num_str - '0');
		}
		else
		{
			if (number < LONG_MIN / 10)
				return (0);
			number = number * 10;
			if (number < LONG_MIN + (*num_str - '0'))
				return (0);
			number -= (*num_str - '0');
		}
		num_str++;
	}
	return ((int)number);
}

/**
 * The ft_atoi() function converts the initial portion of the string
 * pointed to by str to int representation.
 *
 * This function is not thread-safe and also not async-cancel safe.
 *
 * @param	{char*}	str	The string for conversion.
 *
 * @returns	{int}		The converted value or 0 on error.
*/
int	ft_atoi(const char *str)
{
	char	sign;

	sign = '+';
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = *str;
		str++;
	}
	return (convert(str, sign));
}
