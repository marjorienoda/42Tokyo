#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

void *upper_char(void *content)
{
    char *s;
    int i;

    if (!content)
        return (NULL);
    s = ft_strdup((char *)content);
    if (!s)
        return (NULL);
    i = 0;
    while (s[i])
    {
        s[i] = ft_toupper(s[i]);
        i++;
    }
    return ((void *)s);
}

void ft_delone(void *content)
{
    free(content);
}

void	print_list(t_list *lst)
{
	int i = 0;

	while (lst)
	{
		printf("Node %d: %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

void test_ft_lstmap(void)
{
    t_list *list_orig = NULL;
    t_list *list_new = NULL;

    printf("--- Testing ft_lstmap ---\n");
    ft_lstadd_back(&list_orig, ft_lstnew(ft_strdup("hello")));
    ft_lstadd_back(&list_orig, ft_lstnew(ft_strdup("marjorie")));
    ft_lstadd_back(&list_orig, ft_lstnew(ft_strdup("42tokyo")));

    printf("--- Original List ---\n");
    print_list(list_orig);

    list_new = ft_lstmap(list_orig, upper_char, ft_delone);

    printf("--- New Mapped List ---\n");
    print_list(list_new);

    // Limpando ambas
    ft_lstclear(&list_orig, ft_delone);
    ft_lstclear(&list_new, ft_delone);
}