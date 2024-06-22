#include "libft.h"
#include <stdio.h>

int	main(void) {
    t_list *list = ft_list(0);
    ft_list_push(list, ft_strdup("ABC=hello"));
    ft_list_push(list, ft_strdup("VSCODE_NONCE=46b9be33-9a93-4467-b759-f67dae90c639"));
    ft_list_push(list, ft_strdup("VSCODE_INJECTION=1"));
    ft_list_push(list, ft_strdup("LANG=en_US.UTF-8"));
    ft_list_push(list, ft_strdup("COLORTERM=truecolor"));

    char **array = ft_list_to_array(list, sizeof(char *));

	int i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}

	ft_list_clear(&list, free);
	free(array);
	return (0);
}
