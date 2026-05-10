#include "tests.h"
#include <ctype.h>
#include <stdio.h>


static void	case_transformation(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32;
	}
	else
	{
		if (*c >= 'A' && *c <= 'Z')
			*c = *c + 32;
	}
}

static void	run_test(char const *s, void (*f)(unsigned int, char *),
		char *expected, char *test_name)
{
	char *actual;
	int success;
	int len;

	printf("Test: %s\n", test_name);
	success = 1;
	if (s == NULL)
	{
		ft_striteri(NULL, f);
		actual = NULL;
	}
	else
	{
		actual = ft_strdup(s);
		ft_striteri(actual, f);
	}

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
		printf("Expected: %s\n", expected);
		printf("Actual: %s\n", actual);
	}
	else
	{
		printf("❌ FAILED \n");
		printf("Expected: %s\n", expected);
		printf("Actual: %s\n", actual);
	}

	if (actual)
		free(actual);
	printf("---------------------------\n");
}

void	test_ft_striteri(void)
{
	printf("--- Testing ft_striteri ---\n");

	run_test("Marjorie!", case_transformation, "MaRjOrIe!", "Simple case");

	run_test("abcde", case_transformation, "AbCdE", "All lowercase");

	run_test("", case_transformation, "", "Empty string");

	run_test("12345", case_transformation, "12345", "Numbers");

	run_test(NULL, case_transformation, NULL, "Input NULL");
}