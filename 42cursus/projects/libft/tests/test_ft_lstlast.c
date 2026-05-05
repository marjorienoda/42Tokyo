#include "tests.h"

void test_ft_lstlast(void)
{
    printf("--- Testing ft_lstlast ---\n");

    t_list *list = NULL;
    t_list *last;
    
    last = ft_lstlast(list);
    // Test 1: List null
    if(last == NULL)
        printf("Test 1: ✅ SUCCESS \n");
    else
        printf("❌ FAIL \n");

    // Test 2: One element
    t_list *node1 = ft_lstnew("One node");
    list = node1;
    last = ft_lstlast(list);
    if(last == node1)
        printf("Test 1: ✅ SUCCESS \n");
    else
        printf("❌ FAIL \n");
    
    // Test 3: Three element
    t_list *node2 = ft_lstnew("Second node");
    t_list *node3 = ft_lstnew("Third node");
    ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);
    last = ft_lstlast(list);
    if(last == node1)
        printf("Test 1: ✅ SUCCESS \n");
    else
        printf("❌ FAIL \n");

    free(node1);
	free(node2);
	free(node3);
}
