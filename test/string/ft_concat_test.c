/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:16:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/06/08 12:27:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdio.h>

int	main(void)
{
	char *result = NULL;

	ft_concat(&result, 3, "Hello", "    ", "WORLD");
	printf("%s\n", result);
	printf("All tests passed!\n");
	return (EXIT_SUCCESS);
}
