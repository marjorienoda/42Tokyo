#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

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

void	test_ft_lstadd_back(void)
{
    printf("--- Testing ft_lstadd_back ---\n");

    t_list *list = NULL;
    t_list *node1 = ft_lstnew("First Node");
    t_list *node2 = ft_lstnew("Second Node");
    t_list *node3 = ft_lstnew("New Last Node");
    
    ft_lstadd_back(&list, node1);
    printf("Test 1 List Null: \n");
    if(list ->next == NULL)
        printf("✅ SUCCESS \n");
    else
        printf("❌ FAIL \n");
    
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);
    t_list *last = ft_lstlast(list);
    
    printf("Test 2 Three elements \n");
    if (last == node3 && node2->next == node3)
	{
		printf("✅ SUCCESS \n");
        print_list(list);
	}
	else
	{
		printf("❌ FAIL \n");
	}
    free(node1);
	free(node2);
    free(node3);
}