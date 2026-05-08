#include "tests.h"
#include <ctype.h>
#include <stdio.h>

static void	run_test(int c)
{
	int	expected;
	int	actual;

	expected = isascii(c);
	actual = ft_isascii(c);
	printf("Char: %c \n", c);
	printf("Expected: %d | Actual: %d \n", expected, actual);
	if ((expected != 0 && actual != 0) || (expected == 0 && actual == 0))
		printf("✅ SUCCESS\n");
	else
		printf("❌ FAILED\n");
	printf("------------------------------\n");
}

void	test_ft_isascii(void)
{
	printf("--- Testing ft_isascii ---\n");
	run_test(-1);
	run_test(0);
	run_test(65);
	run_test(127);
	run_test(128);
	run_test(255);
}