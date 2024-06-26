/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:53:07 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/02 14:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static char	*find_quote(char *str)
{
	char	prev;

	prev = '\0';
	while (*str != '\0')
	{
		if ((*str == 34 || *str == 39) && prev != '\\')
			return (str);
		prev = *str;
		str++;
	}
	return (NULL);
}

static void	handle_quote(char *str)
{
	char	*open_quote;
	char	*end_quote;

	open_quote = find_quote(str);
	if (open_quote == NULL)
		return ;
	end_quote = find_quote(open_quote + 1);
	while (end_quote != NULL && *end_quote != *open_quote)
		end_quote = find_quote(end_quote + 1);
	if (end_quote == NULL)
		handle_quote(open_quote + 1);
	str = end_quote + 1;
	ft_replace(open_quote, end_quote - open_quote + 1, "\f\n\r\t\v ", 31);
	handle_quote(str);
}

static char	**split_cmd(char *cmd)
{
	char	**tokens;
	int		i;

	handle_quote(cmd);
	ft_replace(cmd, ft_strlen(cmd), "\f\n\r\t\v", ' ');
	tokens = ft_split(cmd, ' ');
	if (tokens != NULL)
	{
		i = 0;
		while (tokens[i] != NULL)
		{
			ft_remove_quote_pair(tokens[i]);
			ft_trim(tokens[i], '\\');
			ft_replace(tokens[i], ft_strlen(tokens[i]), "\x1F", ' ');
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
	if (*dup == '\0' || ft_has_spaces_only(dup))
	{
		tokens = (char **)ft_calloc(2, sizeof(char *));
		if (tokens == NULL)
			return (NULL);
		tokens[0] = dup;
		return (tokens);
	}
	tokens = split_cmd(dup);
	free(dup);
	if (tokens == NULL)
		return (NULL);
	return (tokens);
}
