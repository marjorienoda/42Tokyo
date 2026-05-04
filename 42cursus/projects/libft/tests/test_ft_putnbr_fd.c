#include "tests.h"
#include <stdio.h>

void	test_ft_putnbr_fd(void)
{
	printf("--- Testando ft_putnbr_fd ---\n");

	printf("Número positivo (42): ");
	ft_putnbr_fd(42, 1);
	printf("\n");

	printf("Número zero (0): ");
	ft_putnbr_fd(0, 1);
	printf("\n");

	printf("Número negativo (-123): ");
	ft_putnbr_fd(-123, 1);
	printf("\n");

	printf("Máximo Int (2147483647): ");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");

	printf("Mínimo Int (-2147483648): ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");

	printf("Saída de Erro (FD 2): ");
	ft_putnbr_fd(999, 2);
	printf("\n");

	printf("-----------------------------\n");
}