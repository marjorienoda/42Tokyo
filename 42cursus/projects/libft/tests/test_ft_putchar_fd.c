#include <stdio.h>
#include "tests.h"


void test_ft_putchar_fd(void)
{
	printf("--- Testando ft_putchar_fd ---\n");

	// Teste 1: Escrevendo no Standard Output (1)
	printf("Deve aparecer um 'A' aqui: ");
	ft_putchar_fd('A', 1);
	printf("\n");

	// Teste 2: Escrevendo no Standard Error (2)
	printf("Deve aparecer um 'B' (erro) aqui: ");
	ft_putchar_fd('B', 2);
	printf("\n");

	// Teste 3: Sequência de caracteres
	printf("Deve aparecer '42': ");
	ft_putchar_fd('4', 1);
	ft_putchar_fd('2', 1);
	printf("\n");

	printf("------------------------------\n\n");
}