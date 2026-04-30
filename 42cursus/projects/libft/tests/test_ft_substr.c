#include "tests.h"
#include <stdio.h>

void	test_ft_substr_case(char const *s, unsigned int start, size_t len,
		char *expected)
{
	char	*result;
	size_t	exp_len;

	result = ft_substr(s, start, len);
	// Proteção contra retorno NULL
	if (result == NULL)
	{
		printf("❌ [KO] Input: \"%s\" | Esperado: \"%s\" | Recebido: NULL\n", s,
			expected);
		return ;
	}
	exp_len = ft_strlen(expected);
	// Compara o resultado com o esperado
	if (ft_strncmp(result, expected, exp_len + 1) == 0)
	{
		printf("✅ [OK] Input: \"%s\", Start: %u, Len: %zu -> \"%s\"\n", s,
			start, len, result);
	}
	else
	{
		printf("❌ [KO] Input: \"%s\" | Esperado: \"%s\" | Recebido: \"%s\"\n",
			s, expected, result);
	}
	// Libera a memória alocada
	free(result);
}

void	test_ft_substr(void)
{
	printf("\n--- TESTANDO FT_SUBSTR ---\n");

	// Caso básico
	test_ft_substr_case("Hello World", 6, 5, "World");

	// Start no final da string
	test_ft_substr_case("42 Tokyo", 3, 5, "Tokyo");

	// Start maior que o tamanho da string (Deve retornar string vazia)
	test_ft_substr_case("Marjorie", 15, 1, "");

	// Len maior que o restante da string
	test_ft_substr_case("Estudar C", 0, 50, "Estudar C");

	// Start no meio, mas len é zero
	test_ft_substr_case("Teste", 2, 0, "");

	printf("--------------------------\n");
}