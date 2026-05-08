#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	run_test(char *test_name, char *actual, char *expected)
{
	printf("Test [%s]: ", test_name);
	if (actual == NULL && expected == NULL)
		printf("✅ SUCCESS \n");
	else if (actual != NULL && expected != NULL && strcmp(actual,
			expected) == 0)
		printf("✅ SUCCESS (\"%s\")\n", actual);
	else
		printf("❌ FAILED (Actual: \"%s\" | Expected: \"%s\")\n", actual,
			expected);
	if (actual)
		free(actual);
	printf("---------------------------\n");
}

void	test_ft_strjoin(void)
{
	printf("--- Testing ft_strjoin ---\n");

	run_test("Simple join", ft_strjoin("Hello", " World"), "Hello World");

	run_test("S1 empty", ft_strjoin("", "42"), "42");

	run_test("S2 empty", ft_strjoin("42", ""), "42");

	run_test("Both string are empty", ft_strjoin("", ""), "");

	run_test("Special characters", ft_strjoin("123", " 456"), "123 456");
}