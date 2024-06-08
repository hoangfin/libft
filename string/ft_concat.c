/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:13:01 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/08 12:53:18 by hoatran          ###   ########.fr       */
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

static char	*join_strings(int num_of_strings, va_list args)
{
	va_list	copy_1;
	va_list	copy_2;
	size_t	bytes;
	char	*string;

	va_copy(copy_1, args);
	va_copy(copy_2, args);
	bytes = count_total_bytes(copy_1, num_of_strings);
	string = (char *)malloc((bytes + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	fill(string, copy_2, num_of_strings);
	va_end(copy_1);
	va_end(copy_2);
	return (string);
}

int	ft_concat(char **target, int string_count, ...)
{
	const char	*temp = *target;
	va_list		args;
	char		*str;

	va_start(args, string_count);
	str = join_strings(string_count, args);
	va_end(args);
	if (str == NULL)
		return (-1);
	if (*target == NULL)
		*target = str;
	else
	{
		*target = ft_strjoin(*target, str);
		free(str);
		if (*target == NULL)
		{
			*target = (char *)temp;
			return (-1);
		}
	}
	free((void *)temp);
	return (0);
}