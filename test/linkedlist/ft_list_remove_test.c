#include "libft.h"
#include <stdio.h>

static int	has_same_key(t_node *node, void *data) {
	const char *env_var = (const char *)node->data;
	const char *data_str = (const char *)data;

	char *eq_ptr = ft_strchr(env_var, '=');
	if (ft_strncmp(env_var, data_str, eq_ptr - env_var) == 0)
		return (1);
	return (0);
}

static void print(t_node *node, size_t index)
{
	(void)index;
	printf("%s\n", (char *)node->data);
}

int main(void) {
    t_list *env_list = ft_list(0);
    ft_list_push(env_list, ft_list_node("ABC=hello"));
    ft_list_push(env_list, ft_list_node("VSCODE_NONCE=46b9be33-9a93-4467-b759-f67dae90c639"));
    ft_list_push(env_list, ft_list_node("VSCODE_INJECTION=1"));
    ft_list_push(env_list, ft_list_node("LANG=en_US.UTF-8"));
    ft_list_push(env_list, ft_list_node("COLORTERM=1color"));

    ft_list_foreach(env_list, print);
	ft_list_remove(env_list, "LANG", has_same_key, NULL);
    printf("\nAfter remove key LANG\n");
    ft_list_foreach(env_list, print);
}
