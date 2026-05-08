#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	run_test(const void *s, int c, size_t n, char *test_name)
{
	void	*actual;
	void	*expected;

	actual = ft_memchr(s, c, n);
	expected = memchr(s, c, n);
	printf("Test: %s \n", test_name);
	if (actual == expected)
	{
		printf("✅ SUCCESS\n");
		printf("expected: %p \n", expected);
		printf("actual: %p \n", actual);
	}
	else
		printf("❌ FAILED\n");
	printf("------------------------------\n");
}

void	test_ft_memchr(void)
{
	printf("--- Testing ft_memchr ---\n");

	run_test("Marjorie", 'j', 8, "Found the character");

	run_test("banana", 'a', 6, "The first occurance");

	run_test("Marjorie", 'z', 8, "It doesn't exist");

	run_test("42Tokyo", '\0', 7, "null terminator ('\\0')");

	run_test("Tokyo", 'T', 5, "First character");

	run_test("Hello!", '!', 6, "Last character");

	run_test("test", 'e' + 256, 4, "nt overflow (cast to char)");

	run_test("", 'A', 1, "empty string");

	run_test("Marjorie", 'o', 3, "N < str len");
}