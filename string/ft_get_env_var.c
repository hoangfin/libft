/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:56:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/02 17:00:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_get_env_var(const char *var_key, char **envp)
{
	size_t	length;
	char	*temp;

	length = ft_strlen(var_key);
	while (envp != NULL && *envp != NULL)
	{
		if (ft_strncmp(*envp, var_key, length) == 0)
		{
			temp = ft_strchr(*envp, '=');
			if (temp == NULL)
				return (NULL);
			return (ft_strdup(temp + 1));
		}
	}
	return (NULL);
}
