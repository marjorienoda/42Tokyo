#include "tests.h"
#include <stdio.h>
#include <stdlib.h>


static void	upper_char(void *content)
{
	char *s = (char *)content;
	int i;
	i = 0;
	while (s[i])
	{
		s[i] = (char)ft_toupper((int)s[i]);
		i++;
	}
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

void	test_ft_lstiter(void)
{
	printf("--- Testing ft_lstiter ---\n");
	t_list *list = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("marjorie")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("42tokyo")));

	printf("--- Before ---\n");
	print_list(list);

	ft_lstiter(list->next, upper_char);

	printf("--- After ---\n");
	print_list(list);

	ft_lstclear(&list, free);
}