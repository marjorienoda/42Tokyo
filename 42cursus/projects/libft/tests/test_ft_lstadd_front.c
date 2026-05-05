#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

void	test_ft_lstadd_front(void)
{
    printf("--- Testing ft_lstnew ---\n");

    t_list *list = NULL;
    t_list *node1 = ft_lstnew("Marjorie");
    t_list *node2 = ft_lstnew("42Tokyo");

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    if (list == node2 && list->next == node1)
	{
		printf("✅ SUCESS \n");
		printf("Node 1: %s\n", (char *)list->content);
		printf("Node 2: %s\n", (char *)list->next->content);
	}
	else
	{
		printf("❌ FAIL \n");
	}
	free(node1);
	free(node2);
}