#include "tests.h"
#include <limits.h>

static void	print_result(int original, int actual)
{
	if (actual == original)
		printf("\033[0;32m✅ SUCCESS!\033[0m\n");
	else
		printf("\033[0;31m❌ FAILED! Original: %d | Actual: %d\033[0m\n",
			original, actual);
	printf("----------------------------------------\n");
}

void	test_print_p(void)
{
	int orig;
	int ft;
	char *s1;

	s1 = "testing testing \n testing testing";

	printf("Test 1 (Orig):   [");
	fflush(stdout);
	orig = printf("%p", (void *)-1);
	printf("]\n");
	printf("Test 1 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%p", (void *)-1);
	printf("]");
	print_result(orig, ft);
	// TEST 2
	printf("Test 2 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p", (void *)1);
	printf("]\n");
	printf("Test 2 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p", (void *)1);
	printf("]");
	print_result(orig, ft);
	// TEST 3
	printf("Test 3 (Orig):   [");
	fflush(stdout);
	orig = printf("%p ", (void *)15);
	printf("]\n");
	printf("Test 3 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%p ", (void *)15);
	printf("]");
	print_result(orig, ft);
	// TEST 4
	printf("Test 4 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p ", s1);
	printf("]\n");
	printf("Test 4 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p ", s1);
	printf("]");
	print_result(orig, ft);
	// TEST 5
	printf("Test 5 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p ", (void *)17);
	printf("]\n");
	printf("Test 5 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p ", (void *)17);
	printf("]");
	print_result(orig, ft);
	// TEST 6
	printf("Test 6 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p %p ", (void *)LONG_MAX, (void *)LONG_MIN);
	printf("]\n");
	printf("Test 6 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p %p ", (void *)LONG_MAX, (void *)LONG_MIN);
	printf("]");
	print_result(orig, ft);
	// TEST 7
	printf("Test 7 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p %p ", (void *)INT_MAX, (void *)INT_MIN);
	printf("]\n");
	printf("Test 7 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p %p ", (void *)INT_MAX, (void *)INT_MIN);
	printf("]");
	print_result(orig, ft);
	// TEST 8
	printf("Test 8 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("]\n");
	printf("Test 8 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p %p ", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	printf("]");
	print_result(orig, ft);
	// TEST 9
	printf("Test 9 (Orig):   [");
	fflush(stdout);
	orig = printf(" %p %p %p %p %p %p", (void *)" - ", (void *)"", (void *)"4",
			(void *)"", (void *)"2 ", s1);
	printf("]\n");
	printf("Test 9 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %p %p %p %p %p %p", (void *)" - ", (void *)"", (void *)"4",
			(void *)"", (void *)"2 ", s1);
	printf("]");
	print_result(orig, ft);
	// TEST 10
	printf("Test 10 (Orig):   [");
	fflush(stdout);
	orig = printf(" NULL %p NULL ", (char *)NULL);
	printf("]\n");
	printf("Test 10 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" NULL %p NULL ", (char *)NULL);
	printf("]");
	print_result(orig, ft);
}