/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:01:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/12 15:08:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static void	convert(unsigned long n, char *buffer, int radix)
{
	const char	*hex_values = "0123456789abcdef";
	int			i;

	i = 0;
	while (n != 0)
	{
		if (radix == 16)
			buffer[i++] = hex_values[n % radix];
		else
			buffer[i++] = n % radix + '0';
		n /= radix;
	}
	buffer[i] = '\0';
}

static void	reverse(char *buffer)
{
	size_t	i;
	size_t	mid;
	size_t	length;
	char	temp;

	i = 0;
	length = ft_strlen(buffer);
	mid = i + (length - 1 - i) / 2;
	if (length < 2)
		return ;
	while (i <= mid)
	{
		temp = buffer[i];
		buffer[i] = buffer[length - 1 - i];
		buffer[length - 1 - i] = temp;
		i++;
	}
}

/**
 * The ft_ultoa() returns a string representing the unsigned long received
 * as an argument.
 *
 * @param	{unsigned_int}	n		The unsigned long to convert.
 * @param	{char*}			buffer	The buffer used to hold the string output.
 * 									The recommended size for buffer is:
 * 									sizeof(unsigned int) * 8 + 1
 * @param	{int}			radix	The radix values can be OCTAL, DECIMAL or HEX
 *
 * @returns	{char*}			A char pointer (same as buffer) will be returned.
 * 							When an invalid radix argument is passed, function
 * 							will return NULL. The string representing the
 * 							integer. NULL is returned if the allocation fails.
 *
*/
char	*ft_ultoa(unsigned long number, char *buffer, int radix)
{
	if (radix != 8 && radix != 10 && radix != 16)
		return (NULL);
	if (number == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	convert(number, buffer, radix);
	reverse(buffer);
	return (buffer);
}
