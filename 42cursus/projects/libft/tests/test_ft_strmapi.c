#include "tests.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


static char	case_transformation(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	else
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
	}
	return (c);
}

static void	run_test(char const *s, char (*f)(unsigned int, char),
		char *expected, char *test_name)
{
	char *actual;
	int success;
	int len;

	printf("Test: %s\n", test_name);
	actual = ft_strmapi(s, f);
	success = 1;
	if (!actual || !expected)
	{
		if (actual != expected)
			success = 0;
	}
	else
	{
		len = ft_strlen(expected);
		if (ft_strncmp(actual, expected, len) != 0)
			success = 0;
	}
	if (success)
	{
		printf("✅ SUCCESS \n");
		printf("Input: %s \n", s);
		printf("Actual: %s \n", actual);
	}
	else
	{
		printf("❌ FAILED \n");
		printf("Expected: %s \n", expected);
		printf("Actual: %s \n", actual);
	}
	free(actual);
	printf("---------------------------\n");
}

void	test_ft_strmapi(void)
{
	printf("--- Testing ft_strmapi ---\n");

	run_test("Marjorie!", case_transformation, "MaRjOrIe!", "simple case");

	run_test("abcde", case_transformation, "AbCdE", "All lowercase");

	run_test("", case_transformation, "", "Empty string");

	run_test("121992389283", case_transformation, "", "Numbers");

	run_test(NULL, case_transformation, NULL, "Input NULL");
}