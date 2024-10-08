/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:43:41 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:30:23 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include <stdarg.h>
# include "../common/libft_common.h"

typedef struct s_string
{
	char	*content;
	size_t	length;
}	t_string;

typedef struct s_grid
{
	char	**matrix;
	size_t	row_count;
	size_t	col_count;
}	t_grid;

t_string	*ft_string(char *str);

int		ft_ends_with(const char *string, const char *search_string);
int		ft_has_space(const char *str);
int		ft_has_spaces_only(const char *str);
int		ft_starts_with(const char *string, const char *search_string);

char		*ft_getenv(const char *key, char **envp);
char		*ft_join_strings(int num_of_strings, ...);
char		*ft_join(const char **strings, const char *delim);
char		*ft_strdup_chr(char *source, char delimiter);
char		**ft_matrix(size_t row_count, size_t col_count, int c);
char		**ft_parse_cmd(const char *cmd);
char		*ft_strnstr(const char *str, const char *search, size_t n);

int			ft_concat(char **target, int string_count, ...);

void		ft_del_str_arr(char ***p_array);
void		ft_matrix_delete(char ***matrix);
void		ft_replace(char *str, size_t size, const char *chars, int c);
void		ft_trim_quotes(char	*str);
void		ft_trim(char *str, int c);
void		ft_remove_quote_pair(char *str);

size_t		ft_matrix_count_rows(char **matrix);

#endif
