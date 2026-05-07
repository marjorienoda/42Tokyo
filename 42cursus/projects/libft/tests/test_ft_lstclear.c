#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

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

void test_ft_lstclear(void)
{
    printf("--- Testing ft_lstclear ---\n");
    t_list *list = ft_lstnew(ft_strdup("First Node"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Second Node")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Third Node")));

    printf("--- Before the clear ---\n");
    print_list(list);


    ft_lstclear(&(list->next), ft_delone);

    printf("--- After the clear ---\n");
    print_list(list);
    if(list->next == NULL)
        printf("List null \n");
    ft_lstclear(&list, ft_delone);
}