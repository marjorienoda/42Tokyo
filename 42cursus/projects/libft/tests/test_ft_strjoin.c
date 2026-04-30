#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	check_result(int test_num, char *desc, char *result, char *expected)
{
	printf("Teste %d [%s]: ", test_num, desc);
	if (result == NULL && expected == NULL)
		printf("✅ PASSOU (NULL)\n");
	else if (result != NULL && expected != NULL && strcmp(result,
			expected) == 0)
		printf("✅ PASSOU (\"%s\")\n", result);
	else
		printf("❌ FALHOU (Recebeu: \"%s\" | Esperado: \"%s\")\n", result,
			expected);
	if (result)
		free(result);
}

void	test_ft_strjoin(void)
{
	printf("\n--- Testando ft_strjoin ---\n");

	// Teste 1: Duas strings normais
	check_result(1, "Concatenação simples", ft_strjoin("Hello", " World"),
		"Hello World");

	// Teste 2: Primeira string vazia
	check_result(2, "S1 vazia", ft_strjoin("", "42"), "42");

	// Teste 3: Segunda string vazia
	check_result(3, "S2 vazia", ft_strjoin("42", ""), "42");

	// Teste 4: Ambas as strings vazias
	check_result(4, "Ambas vazias", ft_strjoin("", ""), "");

	// Teste 5: Caracteres especiais/números
	check_result(5, "Números e espaços", ft_strjoin("123", " 456"), "123 456");

	printf("---------------------------\n");
}