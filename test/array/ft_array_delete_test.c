#include "libft.h"
#include <stdio.h>

int main(void)
{
	char **command = (char **)malloc(4 * sizeof(char *));
	command[0] = ft_strdup("echo");
	command[1] = ft_strdup("abc");
	command[2] = ft_strdup("def");
	command[3] = NULL;
	printf("%s\n", command[2]);
	ft_array_delete(command, sizeof(char *), 4, free);
	// printf("%d\n", command == NULL);

	int *numbers = (int *)malloc(4 * sizeof(int));
	numbers[0] = 0;
	numbers[1] = 1;
	numbers[2] = 2;
	numbers[3] = 3;
	ft_array_delete(numbers, sizeof(int), 4, NULL);
	// printf("%d\n", numbers == NULL);
	return (0);
}