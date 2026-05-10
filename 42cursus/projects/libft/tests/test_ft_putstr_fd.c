#include "tests.h"
#include <stdio.h>
#include <unistd.h>


void	test_ft_putstr_fd(void)
{
	printf("--- Testing ft_putstr_fd ---\n");

	ft_putstr_fd("Hello World!", 1);
	printf("\n\n");

	ft_putstr_fd("Error:", 2);
	printf("\n\n");

	printf("[");
	ft_putstr_fd("", 1);
	printf("]\n\n");

	ft_putstr_fd("Parte 1\0Parte 2", 1);
	printf("'\n");

	printf("-----------------------------\n");
}