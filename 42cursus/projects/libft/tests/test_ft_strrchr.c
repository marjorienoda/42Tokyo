#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	run_test(const char *s, int c, char *desc)
{
	char	*expected;
	char	*actual;

	expected = strrchr(s, c);
	actual = ft_strrchr(s, c);
	printf("Test: %s \n", desc);
	if (expected == actual)
	{
		printf("✅ SUCCESS \n");
	}
	else
	{
		printf("❌ FAILED\n");
		printf("expected: %p \n", expected);
		printf("actual: %p \n", actual);
	}
	printf("------------------------------\n");
}

void	test_ft_strrchr(void)
{
	printf("--- Testing ft_strrchr ---\n");
	run_test("Marjorie", 'j', "teste");

	run_test("banana", 'a', "The last occurance");

	run_test("Marjorie", 'z', "no");

	run_test("42Tokyo", '\0', "null terminator ('\\0')");

	run_test("Ovo", 'o', "First character");

	run_test("banana", 'n', "In the middle of the string");

	run_test("test", 't' + 256, "int overflow (cast to char)");

	run_test("", 'A', "empty string");
}