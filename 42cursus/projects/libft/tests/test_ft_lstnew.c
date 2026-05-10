#include "tests.h"
#include <stdio.h>


static void	run_test(void *content, char *test_name)
{
	t_list *actual;

	actual = ft_lstnew(content);
	if (!actual)
	{
		printf("❌ FAILED (%s): Memory allocation failed\n", test_name);
		return ;
	}

	if (actual->content == content && actual->next == NULL)
		printf("✅ SUCCESS (%s)\n", test_name);
	else
		printf("❌ FAILED (%s)\n", test_name);

	free(actual);
}

void	test_ft_lstnew(void)
{
	printf("--- Testing ft_lstnew ---\n");

	int var = 42;

	run_test("Marjorie Y", "String");
	run_test(&var, "Number");
	run_test("", "Empty string");
	run_test(NULL, "NULL");

	printf("--------------------------\n");
}