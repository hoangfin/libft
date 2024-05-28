#include "libft.h"
#include <stdio.h>

static void print(t_node *node, size_t index)
{
	(void)index;
	printf("%s\n", (char *)node->data);
}

int	main(void) {
    t_list *env_list = ft_list(0);
    ft_list_push(env_list, "ABC=hello");
    ft_list_push(env_list, "VSCODE_NONCE=46b9be33-9a93-4467-b759-f67dae90c639");
    ft_list_push(env_list, "VSCODE_INJECTION=1");
    ft_list_push(env_list, "LANG=en_US.UTF-8");
    ft_list_push(env_list, "COLORTERM=truecolor");

    ft_list_foreach(env_list, print);
    printf("\nCloned\n");

	t_list *clone = ft_list_clone(env_list, (void *(*)(void *))ft_strdup, free);
	ft_list_foreach(clone, print);
	return (0);
}
