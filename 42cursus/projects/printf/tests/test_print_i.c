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

void	test_print_i(void)
{
	int		orig;
	int		ft;
	char	*s1;

	s1 = "testing testing \n testing testing";
	printf("Test 1 (Orig):   [");
	fflush(stdout);
	orig = printf("%i", 0);
	printf("]\n");
	printf("Test 1 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%i", 0);
	printf("]");
	print_result(orig, ft);
	// TEST 2
	printf("Test 2 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i", -1);
	printf("]\n");
	printf("Test 2 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i", -1);
	printf("]");
	print_result(orig, ft);
	// TEST 3
	printf("Test 3 (Orig):   [");
	fflush(stdout);
	orig = printf("%i ", 10);
	printf("]\n");
	printf("Test 3 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%i ", 10);
	printf("]");
	print_result(orig, ft);
	// TEST 4
	printf("Test 4 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i ", 100);
	printf("]\n");
	printf("Test 4 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i ", 100);
	printf("]");
	print_result(orig, ft);
	// TEST 5
	printf("Test 5 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i ", 101);
	printf("]\n");
	printf("Test 5 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i ", 101);
	printf("]");
	print_result(orig, ft);
	// TEST 6
	printf("Test 6 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i ", INT_MAX);
	printf("]\n");
	printf("Test 6 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i ", INT_MAX);
	printf("]");
	print_result(orig, ft);
	// TEST 7
	printf("Test 7 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i ", INT_MIN);
	printf("]\n");
	printf("Test 7 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i ", INT_MIN);
	printf("]");
	print_result(orig, ft);
	// // TEST 8
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %i ", LONG_MAX);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %i ", LONG_MAX);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 9
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %i ", LONG_MIN);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %i ", LONG_MIN);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 10
	// printf("Test 10 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %i ", UINT_MAX);
	// printf("]\n");
	// printf("Test 10 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %i ", UINT_MAX);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 11
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %i ", ULONG_MAX);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %i ", ULONG_MAX);
	// printf("]");
	// print_result(orig, ft);
	// TEST 12
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %i ", 9223372036854775807LL);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %i ", 9223372036854775807LL);
	// printf("]");
	// print_result(orig, ft);
	// TEST 13
	printf("Test 13 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i %i ", -1, -100);
	printf("]\n");
	printf("Test 13 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i %i ", -1, -100);
	printf("]");
	print_result(orig, ft);
	// TEST 14
	printf("Test 14 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i %i ", 0, -19999);
	printf("]\n");
	printf("Test 14 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i %i ", 0, -19999);
	printf("]");
	print_result(orig, ft);
	// TEST 15
	printf("Test 15 (Orig):   [");
	fflush(stdout);
	orig = printf(" %i %i ", INT_MAX, INT_MIN);
	printf("]\n");
	printf("Test 15 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %i %i ", INT_MAX, INT_MIN);
	printf("]");
	print_result(orig, ft);
}
