/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:43:41 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/03 00:20:03 by hoatran          ###   ########.fr       */
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
t_bool		ft_ends_with(const char *string, const char *search_string);
t_bool		ft_starts_with(const char *string, const char *search_string);
char		*ft_strdup_chr(char *source, char delimiter);
void		ft_replace(char *str, const char *c_array, int c);
char		**ft_matrix(size_t row_count, size_t col_count, int c);
void		ft_delete_string_array(char ***p_array);
size_t		ft_matrix_count_rows(char **matrix);
void		ft_matrix_delete(char ***matrix);
void		ft_matrix_print(char **matrix);
char		**ft_parse_cmd(const char *cmd);
char		*ft_get_env_var(const char *var_key, char **envp);
char		*ft_join_strings(int num_of_strings, ...);

#endif
