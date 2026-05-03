#include "tests.h"
#include <stdio.h>
#include <unistd.h>


void	test_ft_putstr_fd(void)
{
	printf("--- Testando ft_putstr_fd ---\n");

	// Teste 1: String normal no stdout (1)
	printf("Teste 1 (Saída Normal):\n");
	ft_putstr_fd("Hello, 42 World!", 1);
	printf("\n\n");

	// Teste 2: String no stderr (2)
	printf("Teste 2 (Saída de Erro):\n");
	ft_putstr_fd("Atenção: Erro simulado.", 2);
	printf("\n\n");

	// Teste 3: String vazia
	printf("Teste 3 (String Vazia):\n");
	printf("[");
	ft_putstr_fd("", 1);
	printf("] <- Não deve aparecer nada entre os colchetes.\n\n");

	// Teste 4: Verificando se para no \0
	printf("Teste 4 (Interrupção no \\0):\n");
	printf("Esperado: 'Parte 1'\nObtido:   '");
	ft_putstr_fd("Parte 1\0Parte 2", 1);
	printf("'\n");

	printf("-----------------------------\n");
}