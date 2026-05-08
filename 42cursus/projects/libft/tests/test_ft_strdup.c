#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char		*strdup(const char *s);

static void	run_test(const char *s, char *test_name)
{
	char	*ptr_expec;
	char	*ptr_actual;
	size_t	str_len;

	str_len = ft_strlen(s);
	printf("Test: %s \n", test_name);
	ptr_expec = strdup(s);
	ptr_actual = ft_strdup(s);
	if (ft_strncmp(ptr_expec, ptr_actual, str_len) == 0)
		printf("  ✅ Content: MATCH\n");
	else
		printf("  ❌ Content: MISMATCH (Exp: %s, Got: %s)\n", ptr_expec,
			ptr_actual);
	if (ptr_actual != s)
		printf("  ✅ Memory: NEW ALLOCATION\n");
	else
		printf("  ❌ Memory: SAME ADDRESS (Did not malloc!)\n");
	if (str_len == strlen(ptr_actual))
		printf("  ✅ Length: MATCH\n");
	else
		printf("  ❌ Length: MISMATCH\n");
	free(ptr_expec);
	free(ptr_actual);
	printf("------------------------------\n");
}

void	test_ft_strdup(void)
{
	printf("--- Testing ft_strdup ---\n");

	run_test("Marjorie", "Simple string");

	run_test("", "Empty string");

	run_test("Double\0Null", "Null terminator in the middle of the string");
}