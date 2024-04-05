/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:56:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/05 21:16:51 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_getenv(const char *key, char **envp)
{
	size_t	length;
	char	*temp;

	length = ft_strlen(key);
	while (envp != NULL && *envp != NULL)
	{
		if (ft_strncmp(*envp, key, length) == 0)
		{
			temp = ft_strchr(*envp, '=');
			if (temp == NULL)
				return (NULL);
			return (ft_strdup(temp + 1));
		}
		envp++;
	}
	return (NULL);
}
