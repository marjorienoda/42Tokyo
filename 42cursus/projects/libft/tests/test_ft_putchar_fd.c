#include "tests.h"
#include <stdio.h>


void	test_ft_putchar_fd(void)
{
	printf("--- Testing ft_putchar_fd ---\n");

	printf("Result: \n");
	ft_putchar_fd('A', 1);
	printf("\n");

	printf("Expecting a error message: \n");
	ft_putchar_fd('B', 2);
	printf("\n");

	printf("Expected: '42': Actual: \n");
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);
	printf("\n");

	printf("------------------------------\n\n");
}