#include "tests.h"
#include <stdio.h>
#include <stdlib.h>


static void	ft_delone(void *content)
{
	free(content);
}

static void	print_list(t_list *lst)
{
	int i = 0;

	while (lst)
	{
		printf("Node %d: %s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

void	test_ft_lstdelone(void)
{
	printf("--- Testing ft_lstdelone ---\n");

	t_list *node1 = ft_lstnew(ft_strdup("First Node"));
	t_list *node2 = ft_lstnew(ft_strdup("Second Node"));
	t_list *node3 = ft_lstnew(ft_strdup("Third Node"));

	node1->next = node2;
	node2->next = node3;
	print_list(node1);

	ft_lstdelone(node2, ft_delone);
	node1->next = node3;

	print_list(node1);
	ft_lstdelone(node1, ft_delone);
	ft_lstdelone(node3, ft_delone);
}