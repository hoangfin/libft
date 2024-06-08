/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:16:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/08 13:08:20 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>

int	main(void)
{
	const char *filename = "Makefile";
	const char *search = "Make*";

	char *match = ft_strnstr(filename, search, 4);
	printf("%s\n", match);
	printf("All tests passed!\n");
	return (EXIT_SUCCESS);
}
