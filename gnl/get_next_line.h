/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:44:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/19 00:17:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../common/libft_common.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int	get_next_line(int fd, char **line);

#endif