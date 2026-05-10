#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	run_test_calloc(size_t count, size_t size, char *test_name)
{
	void	*ptr_expec;
	void	*ptr_actual;
	size_t	total_size;

	total_size = count * size;
	printf("Test: %s \n", test_name);
	ptr_expec = calloc(count, size);
	ptr_actual = ft_calloc(count, size);
	if ((ptr_expec == NULL && ptr_actual != NULL) || (ptr_expec != NULL
			&& ptr_actual == NULL))
	{
		printf("❌ FAILED\n Error NULL \n");
		printf("Expected %p | Actual: %p \n", ptr_expec, ptr_actual);
	}
	else if (ptr_expec != NULL)
	{
		if (ft_memcmp(ptr_expec, ptr_actual, total_size) == 0)
			printf("✅ SUCCESS: content matches \n");
		else
			printf("❌ FAILED\n Error NULL \n");
	}
	else
	{
		printf("✅ SUCCESS: both returned NULL \n");
	}
	free(ptr_expec);
	free(ptr_actual);
	printf("------------------------------\n");
}

void	test_ft_calloc(void)
{
	printf("--- Testing ft_calloc ---\n");

	run_test_calloc(10, sizeof(char), "Normal allocation (10 chars)");

	run_test_calloc(5, sizeof(int), "Array of 5 ints");

	run_test_calloc(0, sizeof(char), "Count is zero");
	run_test_calloc(10, 0, "Size is zero");
	run_test_calloc(0, 10, "Size is zero");
}