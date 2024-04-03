/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:50:37 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/03 12:05:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static size_t	count_total_bytes(va_list args, int args_length)
{
	int		i;
	size_t	bytes;

	i = 0;
	bytes = 0;
	while (i < args_length)
	{
		bytes += ft_strlen(va_arg(args, char *));
		i++;
	}
	return (bytes);
}

static void	fill(char *string, va_list args, int args_length)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < args_length)
	{
		temp = va_arg(args, char *);
		while (*temp != '\0')
		{
			*string = *temp;
			string++;
			temp++;
		}
		i++;
	}
	*string = '\0';
}

char	*ft_join_strings(int num_of_strings, ...)
{
	va_list	args_1;
	va_list	args_2;
	size_t	bytes;
	char	*string;

	va_start(args_1, num_of_strings);
	bytes = count_total_bytes(args_1, num_of_strings);
	va_end(args_1);
	string = (char *)malloc((bytes + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	va_start(args_2, num_of_strings);
	fill(string, args_2, num_of_strings);
	va_end(args_2);
	return (string);
}
