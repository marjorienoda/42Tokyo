#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	run_test(char const *s1, char const *set, char *expected,
		char *test_name)
{
	char	*actual;
	size_t	expected_len;

	expected_len = ft_strlen(expected);
	actual = ft_strtrim(s1, set);
	printf("Test: %s  \n", test_name);
	if (expected == NULL && actual == NULL)
		printf("✅ SUCCESS (NULL)\n");
	else
	{
		if (ft_memcmp(expected, actual, expected_len) == 0)
			printf("✅ SUCCESS: content matches \n");
		else
			printf("❌ FAILED\n Error NULL \n");
	}
	if (actual)
		free(actual);
	printf("---------------------------\n");
}

void	test_ft_strtrim(void)
{
	printf("--- Testing ft_strtrim ---\n");
	run_test("   hello world   ", " ", "hello world", "Spaces");
	run_test("...---sos---...", ".-", "sos", "Specials characters");
	run_test("42 Tokyo", "xyz", "42 Tokyo", "Set doesnt exist");
	run_test("aaaaaaa", "a", "", "Removes everything");
	run_test("", "abc", "", "String empty");
	run_test("marjorie", "", "marjorie", "Set empyt");
	run_test("abaaba", "a", "baab", "Characters in the middle");
	run_test("xxxz  test with x and z and x .  zx  xx z", "z x", "	",
			"Characters in the middle");
}
