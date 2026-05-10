#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	print_and_free(char **res)
{
	int	i;

	if (!res)
	{
		printf("Actual: NULL\n");
		return ;
	}
	i = 0;
	while (res[i])
	{
		printf("  [%d]: \"%s\"\n", i, res[i]);
		printf("  [%d]: Address: %p | Content: %s\n", i, (void *)res[i],
			res[i]);
		free(res[i]);
		i++;
	}
	free(res);
}

static void	run_test(char const *s, char c, char **expected, char *test_name)
{
	char	**actual;
	int		i;
	int		success;
	size_t	len;

	actual = ft_split(s, c);
	printf("Test: %s \n", test_name);
	i = 0;
	success = 1;
	if (!actual || !expected)
	{
		if (actual != expected)
			success = 0;
	}
	else
	{
		while (expected[i] && actual[i])
		{
			len = ft_strlen(expected[i]) + 1;
			if (ft_strncmp(expected[i], actual[i], len) != 0)
			{
				success = 0;
				break ;
			}
			i++;
		}
		if (expected[i] != actual[i])
			success = 0;
	}
	if (success)
		printf("✅ SUCCESS \n");
	else
		printf("❌ FAILED\n");
	if (actual)
		print_and_free(actual);
	printf("------------------------------\n");
}

void	test_ft_split(void)
{
	printf("--- Testing ft_split ---\n");

	char *exp1[] = {"Hello", "World", NULL};
	run_test("Hello World", ' ', exp1, "simple case");

	char *exp2[] = {"Hello", "world", "!", NULL};
	run_test("Hello,,,world,,!", ',', exp2, "Multiple delimiters");

	char *exp3[] = {"Hello", "World", NULL};
	run_test("---Hello-World---", '-', exp3, "Start and end delimiters");

	char *exp4[] = {NULL};
	run_test("", 'z', exp4, "Empty string");

	char *exp5[] = {NULL};
	run_test(",,,,,,,,,,", ',', exp5, "Only delimiters");
}