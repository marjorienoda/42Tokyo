#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

void	test_ft_lstadd_front(void)
{
    printf("--- Testando ft_lstnew ---\n");

    t_list *list = NULL;
    t_list *node1 = ft_lstnew("Marjorie");
    t_list *node2 = ft_lstnew("42Tokyo");

    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    if (list == node2 && list->next == node1)
	{
		printf("✅ SUCESSO: O no2 está na frente do no1.\n");
		printf("Conteúdo do primeiro: %s\n", (char *)list->content);
		printf("Conteúdo do segundo: %s\n", (char *)list->next->content);
	}
	else
	{
		printf("❌ FALHA: A ordem dos nós está incorreta.\n");
	}
	free(node1);
	free(node2);
}