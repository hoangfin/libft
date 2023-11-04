/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:35 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/26 17:34:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(int number, char *buffer)
{
	size_t	i;
	long	big_int;

	if (number == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return ;
	}
	i = 0;
	big_int = number;
	if (big_int < 0)
		big_int = -big_int;
	while (big_int != 0)
	{
		buffer[i++] = big_int % 10 + '0';
		big_int /= 10;
	}
	if (number < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
}

static void	reverse(char *str, size_t str_len)
{
	size_t	i;
	size_t	mid;
	char	temp;

	i = 0;
	mid = i + (str_len - 1 - i) / 2;
	if (str_len < 2)
		return ;
	while (i <= mid)
	{
		temp = str[i];
		str[i] = str[str_len - 1 - i];
		str[str_len - 1 - i] = temp;
		i++;
	}
}

/**
 * The ft_itoa() function returns a string representing the integer
 * received as an argument. Negative numbers must be handled.
 *
 * @param	{int}	n		The integer to convert.
 *
 * @returns	{char*}			The string representing the integer.
 * 							NULL is returned if the allocation fails.
*/
char	*ft_itoa(int n)
{
	char	buff[32];
	size_t	length;
	char	*num_str;

	convert(n, buff);
	length = ft_strlen(buff);
	num_str = (char *)malloc((length + 1) * sizeof(char));
	if (num_str != NULL)
	{
		ft_strlcpy(num_str, buff, length + 1);
		reverse(num_str, length);
	}
	return (num_str);
}
