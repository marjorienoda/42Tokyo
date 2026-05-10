#include "tests.h"
#include <stdio.h>
#include <unistd.h>


void	test_ft_putendl_fd(void)
{
	printf("--- Testing putendl_fd ---\n");

	printf("Test 1 (Simple string):\n");
	ft_putendl_fd("Hello, 42 World!", 1);
	printf("\n");

	printf("Test 2 (Error message):\n");
	ft_putendl_fd("Error", 2);
	printf("\n");

	printf("Test 3 (String empty):\n");
	printf("[");
	ft_putendl_fd("", 1);
	printf("] \n\n");

	printf("Test 4 (Stop in \\0):\n");
	printf("Expected: 'Part 1'\nActual:   '");
	ft_putendl_fd("Part 1\0Part 2", 1);

	printf("Test 5 (FD = 4):\n");
	ft_putendl_fd("end!", 4);
	printf("-----------------------------\n");
}