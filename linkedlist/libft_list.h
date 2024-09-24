/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:04:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/09/25 00:29:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "../common/libft_common.h"

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	size_t	length;
	int		is_circular;
}	t_list;

int		ft_list_push_all(t_list *dest, t_list *src, void *(*copy)(void *));
int		ft_list_push(t_list *list, void *data);
int		ft_list_for_each(\
			t_list *list, \
			void *data, \
			int (*fn)(t_node *, void *, size_t) \
		);

size_t	ft_list_unshift(t_list *list, t_node *node);
int	ft_list_every(t_list *list, int (*pred)(void *, size_t, t_list *));
int	ft_list_some(t_list *list, int (*pred)(void *, size_t, t_list *));
void	*ft_list_to_array(t_list *list, size_t element_size);
t_list	*ft_list_map(t_list *list, void *(*fn)(void *), void (*delete)(void *));
t_list	*ft_list(int is_circular);
t_node	*ft_list_node(void *data);
t_node	*ft_list_shift(t_list *list);
t_node	*ft_list_pop(t_list *list);
void	ft_list_clear(t_list **list, void (*delete)(void *));
void	ft_list_foreach(t_list *list, void (*fn)(t_node *, size_t));

t_list	*ft_list_clone(\
			t_list *src, \
			void *(*copy)(void *), \
			void (*delete)(void *) \
		);

void	ft_list_remove(\
			t_list *list, \
			void *data, \
			int (*pred)(t_node *, void *), \
			void (*delete)(void *) \
		);

t_node	*ft_list_find(\
			t_list *list, \
			void *data, \
			int (*pred)(t_node *, void *) \
		);

void	*ft_list_reduce( \
			t_list *list, \
			void *(*fn)(void *, void *, size_t, t_list *), \
			void *initial_value \
		);

int		ft_list_index_of( \
			t_list *list, \
			void *data, \
			int (*pred)(t_node *, void *) \
		);

#endif
