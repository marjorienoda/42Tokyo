#include "tests.h"
#include <stdio.h>
#include <string.h>

char		*strnstr(const char *big, const char *little, size_t len);
static void	run_test(const char *big, const char *little, size_t len,
		char *test_name)
{
	char	*expected;
	char	*actual;

	expected = strnstr(big, little, len);
	actual = ft_strnstr(big, little, len);
	printf("Test: %s \n", test_name);
	if (expected == actual)
	{
		printf("✅ SUCCESS \n");
		printf("expected: %p \n", expected);
		printf("actual: %p \n", actual);
		printf("expected: %s \n", expected);
		printf("actual: %s \n", actual);
	}
	else
	{
		printf("❌ FAILED\n");
		printf("expected: %p \n", expected);
		printf("actual: %p \n", actual);
	}
	printf("------------------------------\n");
}

void	test_ft_strnstr(void)
{
	printf("--- Testing ft_strnstr ---\n");

	run_test("123987", "98", 4, "Find little but len is too short");

	run_test("libft-test-tokyo", "test", 10, "little ends exactly at len");

	run_test("abc", "abcdef", 10, "Len is bigger than little size");

	run_test("Marjorie", "", 10, "Empty string");

	run_test("Marjorie", "Maria", 8, "Not found");

	run_test("Marjorie", "Mar", 3, "Found at start");

	run_test("Marjorie", "Mar", 0, "len = 0 ");
}