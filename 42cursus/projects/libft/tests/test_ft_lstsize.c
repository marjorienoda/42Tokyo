#include "tests.h"

void test_ft_lstsize(void)
{
    printf("--- Testing ft_lstsize ---\n");
    int lenght;

    t_list *list = NULL;
    
    // Test 1: List null

    lenght = ft_lstsize(list);
    printf("Test 1: List null | Exp: 0 Result %d \n", lenght);

    // Test 2: One element
    ft_lstadd_front(&list, ft_lstnew("First"));
    lenght = ft_lstsize(list);
    printf("Test 2: One element | Exp: 1 Result %d \n", lenght);
    
    // Test 3: 3 elements
    ft_lstadd_front(&list, ft_lstnew("Second"));
    ft_lstadd_front(&list, ft_lstnew("Third"));
    lenght = ft_lstsize(list);
    printf("Test 2: 3 elements | Exp: 3 Result %d \n", lenght);

    while (list)
	{
		t_list *temp = list->next;
		free(list);
		list = temp;
	}
}
