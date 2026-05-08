#include "tests.h"
#include <stdio.h>
#include <stdlib.h>


static void	run_test(char *str)
{
	int expected = atoi(str);
	int actual = ft_atoi(str);

	printf("Input: [%s] \n", str);
	if (expected == actual)
	{
		printf("✅ SUCCESS\n");
		printf("Result expecter: %d", expected);
	}
	else
		printf("❌ FAILED\n");
	printf("------------------------------\n");
}
void	test_ft_atoi(void)
{
	printf("--- Testing ft_atoi ---\n");

	run_test("42");
	run_test("-42");
	run_test("       42");
	run_test("       -42");
	run_test("\t\n\v\f\r 12345");
	run_test("+12345");
	run_test("0");
	run_test("-0");
	run_test("12abdc345");
	run_test("000012345");
	run_test("2147483647");
	run_test("-2147483648");
	run_test("");
	run_test("    +");
	run_test("    -");
	run_test("marjorie");
}