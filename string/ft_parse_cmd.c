/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:53:07 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/03 17:28:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static void	handle_quote(char *str)
{
	char	*end_quote;

	while (*str != '\0' && *str != 34 && *str != 39)
		str++;
	if (*str == '\0')
		return ;
	end_quote = str + 1;
	while (*end_quote != '\0' && *end_quote != *str)
		end_quote++;
	if (*end_quote == '\0')
		handle_quote(str + 1);
	else
	{
		while (str != end_quote)
		{
			if (ft_isspace(*str))
				*str = 31;
			str++;
		}
		handle_quote(str + 1);
	}
}

static void	remove_open_end_quotes(char **str)
{
	size_t	length;
	char	*temp;

	if (str == NULL || *str == NULL || *str == '\0')
		return ;
	length = ft_strlen(*str);
	if (**str != 34 && **str != 39)
		return ;
	if ((*str)[0] != (*str)[length - 1])
		return ;
	temp = (char *)malloc((length - 1) * sizeof(char));
	if (temp == NULL)
		return ;
	ft_strlcpy(temp, *str + 1, length - 1);
	free(*str);
	*str = temp;
}

static char	**split_cmd(char *cmd)
{
	const char	patterns[2] = {31, '\0'};
	char		**tokens;
	int			i;

	handle_quote(cmd);
	ft_replace(cmd, "\f\n\r\t\v", ' ');
	tokens = ft_split(cmd, ' ');
	if (tokens != NULL)
	{
		i = 0;
		while (tokens[i] != NULL)
		{
			remove_open_end_quotes(&tokens[i]);
			ft_replace(tokens[i], patterns, ' ');
			i++;
		}
	}
	return (tokens);
}

char	**ft_parse_cmd(const char *cmd)
{
	char	*dup;
	char	**tokens;

	if (cmd == NULL)
		return (NULL);
	dup = ft_strdup(cmd);
	if (dup == NULL)
		return (NULL);
	tokens = split_cmd(dup);
	free(dup);
	if (tokens == NULL || tokens[0] == NULL)
		return (free(tokens), NULL);
	return (tokens);
}
