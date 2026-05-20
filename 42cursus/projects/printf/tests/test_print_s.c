#include "tests.h"

static void	print_result(int original, int actual)
{
	if (actual == original)
		printf("\033[0;32m✅ SUCCESS!\033[0m\n");
	else
		printf("\033[0;31m❌ FAILED! Original: %d | Actual: %d\033[0m\n",
			original, actual);
	printf("----------------------------------------\n");
}

void	test_print_s(void)
{
	int		orig;
	int		ft;
	char	*s2;

	s2 = "testing testing";
	// TEST 1
	printf("Test 1 (Orig):   [");
	fflush(stdout);
	orig = printf("%s", "");
	printf("]\n");
	printf("Test 1 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%s", "");
	printf("]");
	print_result(orig, ft);
	// TEST 2
	printf("Test 2 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s", "");
	printf("]\n");
	printf("Test 2 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s", "");
	printf("]");
	print_result(orig, ft);
	// TEST 3
	printf("Test 3 (Orig):   [");
	fflush(stdout);
	orig = printf("%s ", "");
	printf("]\n");
	printf("Test 3 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%s ", "");
	printf("]");
	print_result(orig, ft);
	// TEST 4
	printf("Test 4 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s ", "");
	printf("]\n");
	printf("Test 4 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s ", "");
	printf("]");
	print_result(orig, ft);
	// TEST 5
	printf("Test 5 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s ", "-");
	printf("]\n");
	printf("Test 5 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s ", "-");
	printf("]");
	print_result(orig, ft);
	// TEST 6
	printf("Test 6 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s %s ", "", "-");
	printf("]\n");
	printf("Test 6 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s %s ", "", "-");
	printf("]");
	print_result(orig, ft);
	// TEST 7
	printf("Test 7 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s %s ", " - ", "");
	printf("]\n");
	printf("Test 7 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s %s ", " - ", "");
	printf("]");
	print_result(orig, ft);
	// TEST 8
	printf("Test 8 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("]\n");
	printf("Test 8 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	printf("]");
	print_result(orig, ft);
	// TEST 9
	printf("Test 9 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("]\n");
	printf("Test 9 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	printf("]");
	print_result(orig, ft);
	// TEST 10
	printf("Test 10 (Orig):   [");
	fflush(stdout);
	orig = printf(" NULL %s NULL ", (char *)NULL);
	printf("]\n");
	printf("Test 10 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" NULL %s NULL ", (char *)NULL);
	printf("]");
	print_result(orig, ft);
}
