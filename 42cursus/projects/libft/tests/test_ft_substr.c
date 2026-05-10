#include "tests.h"
#include <stdio.h>

static void	test_ft_substr_case(char const *s, unsigned int start, size_t len,
		char *expected)
{
	char	*result;
	size_t	exp_len;

	result = ft_substr(s, start, len);
	if (result == NULL)
	{
		printf("❌ FAILED Input: \"%s\" | Expected: \"%s\" | Actual: NULL\n", s,
			expected);
		return ;
	}
	exp_len = ft_strlen(expected);
	if (ft_strncmp(result, expected, exp_len + 1) == 0)
	{
		printf("✅ SUCCESS Input: \"%s\", Start: %u, Len: %zu -> \"%s\"\n", s,
			start, len, result);
	}
	else
	{
		printf("❌ FAILED Input: \"%s\" | Expected: \"%s\" | Actual: \"%s\"\n",
			s, expected, result);
	}
	free(result);
	printf("--------------------------\n");
}

void	test_ft_substr(void)
{
	printf("--- Testing ft_substr ---\n");

	test_ft_substr_case("Hello World", 6, 5, "World");

	test_ft_substr_case("42 Tokyo", 3, 5, "Tokyo");

	test_ft_substr_case("Marjorie", 15, 1, "");

	test_ft_substr_case("Project libft 42 Tokyo", 0, 50,
		"Project libft 42 Tokyo");

	test_ft_substr_case("Test", 2, 0, "");

	test_ft_substr_case("hola", 0, 1, "h");
}