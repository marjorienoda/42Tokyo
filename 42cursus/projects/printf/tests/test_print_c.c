#include "tests.h"

static void	run_case(int test_num, int c)
{
	int	ret_ft;
	int	ret_orig;

	printf("Test %d (Orig): [", test_num);
	fflush(stdout);
	ret_orig = printf("%c", c);
	printf("] -> Retorno: %d\n", ret_orig);
	printf("Test %d (Actual): [", test_num);
	fflush(stdout);
	ret_ft = ft_printf("%c", c);
	printf("] -> Retorno: %d\n", ret_ft);
	if (ret_ft == ret_orig)
		printf("\033[0;32m✅ SUCCESS!\033[0m\n");
	else
		printf("\033[0;31m[❌ FAILED! Orig: %d | Ft: %d\033[0m\n", ret_orig,
			ret_ft);
	printf("----------------------------------------\n");
}

void	test_print_c(void)
{
	run_case(1, '0');
	run_case(2, '0' - 256);
	run_case(3, '0' + 256);
	run_case(4, 0);
	run_case(5, ' ');
	run_case(6, '\n');
	run_case(7, '\t');
	run_case(8, '@');
}
