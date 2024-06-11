/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:12:06 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/11 14:43:37 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*str1 = (unsigned char *)s1;
	const unsigned char	*str2 = (unsigned char *)s2;
	int					diff;

	while (*str1 != '\0' && *str2 != '\0')
	{
		diff = *str1 - *str2;
		if (diff != 0)
			break ;
		str1++;
		str2++;
	}
	diff = *str1 - *str2;
	return (diff);
}
