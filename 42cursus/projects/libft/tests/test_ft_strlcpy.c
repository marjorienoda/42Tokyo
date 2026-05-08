#include "tests.h"
#include <stdio.h>
#include <string.h>

size_t		strlcpy(char *dst, const char *src, size_t size);

static void	run_test(char *d_ft, char *d_orig, const char *s, size_t sz,
		char *desc)
{
	size_t	ret_ft;
	size_t	ret_orig;

	printf("Test: %s (size=%zu)\n", desc, sz);
	ret_ft = ft_strlcpy(d_ft, s, sz);
	ret_orig = strlcpy(d_orig, s, sz);
	printf("Src: \"%s\" | Size: %zu\n", s, sz);
	printf("Expected Dest: [%s] | Actual Dest: [%s]\n", d_orig, d_ft);
	printf("Expected Ret: %zu | Actual Ret: %zu\n", ret_orig, ret_ft);
	if (ret_ft == ret_orig && strcmp(d_ft, d_orig) == 0)
		printf("✅ SUCCESS\n");
	else
		printf("❌ FAILED\n");
	printf("------------------------------\n");
}

void	test_ft_strlcpy(void)
{
	printf("--- Testing ft_strlcpy ---\n");

	char df1[20], do1[20];
	run_test(df1, do1, "Hello", 20, "Large string");

	char df2[5], do2[5];
	run_test(df2, do2, "42Tokyo", 5, "Truncate");

	char df3[10] = "Default", do3[10] = "Default";
	run_test(df3, do3, "Test", 0, "Size 0");

	char df4[10], do4[10];
	run_test(df4, do4, "42", 1, "Size 1");
}