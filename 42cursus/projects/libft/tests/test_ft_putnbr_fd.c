#include "tests.h"
#include <stdio.h>


void	test_ft_putnbr_fd(void)
{
	printf("--- Testing ft_putnbr_fd ---\n");

	ft_putnbr_fd(42, 1);
	printf("\n");

	ft_putnbr_fd(0, 1);
	printf("\n");

	ft_putnbr_fd(-123, 1);
	printf("\n");

	ft_putnbr_fd(2147483647, 1);
	printf("\n");

	ft_putnbr_fd(-2147483648, 1);
	printf("\n");

	ft_putnbr_fd(999, 2);
	printf("\n");

	printf("-----------------------------\n");
}