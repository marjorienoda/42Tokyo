#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	print_and_free(char **res)
{
	int	i;

	if (!res)
	{
		printf("Result: NULL\n");
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

void	test_ft_split(void)
{
	char **res;

	printf("--- Testing ft_split ---\n");

	printf("Test 1: '  Good  morning  !  ', sep: ' '\n");
	res = ft_split("  Good  morning  !  ", ' ');
	print_and_free(res);
	printf("\n");

	printf("Test 2: '42Tokyo', sep: '-'\n");
	res = ft_split("42Tokyo", '-');
	print_and_free(res);
	printf("\n");

	printf("Test 3: '-------', sep: '-'\n");
	res = ft_split("-------", '-');
	print_and_free(res);
	printf("\n");

	printf("Test 4: '', sep: ' '\n");
	res = ft_split("", ' ');
	print_and_free(res);
	printf("\n");

	printf("Test 5: 'banana', sep: '\\0'\n");
	res = ft_split("banana", '\0');
	print_and_free(res);
}