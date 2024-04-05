/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_quotes_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:16:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/05 20:42:45 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char case_1[] = "'\"Hello\"'";
	char case_2[] = "'\"Hello\"";
	char case_3[] = "''";
	char case_4[] = "'";

	ft_trim_quotes(case_1);
	assert(strcmp(case_1, "\"Hello\"") == 0);

	ft_trim_quotes(case_2);
	assert(strcmp(case_2, "\'\"Hello\"") == 0);

	ft_trim_quotes(case_3);
	assert(strcmp(case_3, "") == 0);

	ft_trim_quotes(case_4);
	assert(strcmp(case_4, "'") == 0);
	printf("All tests passed!\n");
	return (EXIT_SUCCESS);
}
