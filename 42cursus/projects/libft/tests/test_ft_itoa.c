#include "tests.h"
#include <limits.h>
#include <stdio.h>

void	run_test(int nb, char *expected)
{
	char	*res;

	res = ft_itoa(nb);
	printf("[Teste]: n = %d | Esperado: %s | Obtido: %s", nb, expected, res);
	printf("\n");
}

void	test_ft_itoa(void)
{
	run_test(42, "42");
	run_test(0, "0");
	run_test(-5, "-5");
	run_test(123456789, "123456789");
	run_test(-2147483647, "-2147483647");

	// O teste decisivo:
	run_test(INT_MIN, "-2147483648");

	// O limite superior:
	run_test(INT_MAX, "2147483647");
}