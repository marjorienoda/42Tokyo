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

void	test_print_x(void)
{
	int	orig;
	int	ft;

	printf("Test 1 (Orig):   [");
	fflush(stdout);
	orig = printf("%x", 0);
	printf("]\n");
	printf("Test 1 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%x", 0);
	printf("]");
	print_result(orig, ft);
	// TEST 2
	printf("Test 2 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x", -1);
	printf("]\n");
	printf("Test 2 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x", -1);
	printf("]");
	print_result(orig, ft);
	// TEST 3
	printf("Test 3 (Orig):   [");
	fflush(stdout);
	orig = printf("%x ", 10);
	printf("]\n");
	printf("Test 3 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%x ", 10);
	printf("]");
	print_result(orig, ft);
	// TEST 4
	printf("Test 4 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x ", 100);
	printf("]\n");
	printf("Test 4 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x ", 100);
	printf("]");
	print_result(orig, ft);
	// TEST 5
	printf("Test 5 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x ", 101);
	printf("]\n");
	printf("Test 5 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x ", 101);
	printf("]");
	print_result(orig, ft);
	// TEST 6
	printf("Test 6 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x ", INT_MAX);
	printf("]\n");
	printf("Test 6 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x ", INT_MAX);
	printf("]");
	print_result(orig, ft);
	// TEST 7
	printf("Test 7 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x ", INT_MIN);
	printf("]\n");
	printf("Test 7 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x ", INT_MIN);
	printf("]");
	print_result(orig, ft);
	// // TEST 8
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %x ", LONG_MAX);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %x ", LONG_MAX);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 9
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %x ", LONG_MIN);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %x ", LONG_MIN);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 10
	// printf("Test 10 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %x ", UINT_MAX);
	// printf("]\n");
	// printf("Test 10 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %x ", UINT_MAX);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 11
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %x ", ULONG_MAX);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %x ", ULONG_MAX);
	// printf("]");
	// print_result(orig, ft);
	// // TEST 12
	// printf("Test 5 (Orig):   [");
	// fflush(stdout);
	// orig = printf(" %x ", 9223372036854775807LL);
	// printf("]\n");
	// printf("Test 5 (Actual): [");
	// fflush(stdout);
	// ft = ft_printf(" %x ", 9223372036854775807LL);
	// printf("]");
	// print_result(orig, ft);
	// TEST 13
	printf("Test 13 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x %x ", -1, -100);
	printf("]\n");
	printf("Test 13 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x %x ", -1, -100);
	printf("]");
	print_result(orig, ft);
	// TEST 14
	printf("Test 14 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x %x ", 0, -19999);
	printf("]\n");
	printf("Test 14 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x %x ", 0, -19999);
	printf("]");
	print_result(orig, ft);
	// TEST 15
	printf("Test 15 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x %x ", INT_MAX, INT_MIN);
	printf("]\n");
	printf("Test 15 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x %x ", INT_MAX, INT_MIN);
	printf("]");
	print_result(orig, ft);
	// TEST 16
	printf("Test 16 (Orig):   [");
	fflush(stdout);
	orig = printf(" %x %x %x %x", INT_MAX, INT_MIN, 0, -42);
	printf("]\n");
	printf("Test 16 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %x %x %x %x", INT_MAX, INT_MIN, 0, -42);
	printf("]");
	print_result(orig, ft);
}
