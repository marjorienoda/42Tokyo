#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	run_test(const char *s1, const char *s2, size_t n, char *desc)
{
	int	expected;
	int	actual;

	expected = strncmp(s1, s2, n);
	actual = ft_strncmp(s1, s2, n);
	printf("Test: %s \n", desc);
	if ((expected == 0 && actual == 0) || (expected < 0 && actual < 0)
		|| (expected > 0 && actual > 0))
		printf("✅ SUCCESS \n");
	else
	{
		printf("❌ FAILED\n");
		printf("expected: %d | actual: %d \n", expected, actual);
	}
	printf("------------------------------\n");
}

void	test_ft_strncmp(void)
{
	printf("--- Testing ft_strncmp ---\n");

	run_test("marjorie", "Marjorie", 1, "Case sensitivity");

	run_test("Marjorie", "Marjorie", 8, "Same string");

	run_test("abcdef", "abcZXY", 3, "Limit n before difference");

	run_test(" ", "M", 1, "Space vs Letter");

	run_test("test", "", 4, "String vs Empty");

	run_test("abc", "xyz", 0, "n = zero");

	run_test("test\x80", "test\x00", 6, "Unsigned char check");
}