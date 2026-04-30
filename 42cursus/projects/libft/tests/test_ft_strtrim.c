#include "tests.h"
#include <stdio.h>
#include <string.h>

static void	check_result(int test_num, char *desc, char *result, char *expected)
{
	printf("Teste %02d [%s]: ", test_num, desc);
	// Caso ambos sejam NULL (algumas funções podem retornar NULL em erro)
	if (result == NULL && expected == NULL)
		printf("✅ PASSOU (NULL)\n");
	// Caso o conteúdo seja igual ao esperado
	else if (result != NULL && expected != NULL && strcmp(result,
			expected) == 0)
		printf("✅ PASSOU (\"%s\")\n", result);
	// Caso falhe
	else
	{
		printf("❌ FALHOU!\n");
		printf("      Recebeu: [%s]\n", result ? result : "NULL");
		printf("      Esperado: [%s]\n", expected ? expected : "NULL");
	}
	// Limpa a memória alocada pela sua função ft_
	if (result)
		free(result);
}

void	test_ft_strtrim(void)
{
	printf("\n--- Testando ft_strtrim ---\n");

	// Teste 1: Caso padrão (espaços nas bordas)
	check_result(1, "Espaços nas bordas", ft_strtrim("   hello world   ", " "),
		"hello world");

	// Teste 2: Múltiplos caracteres no set
	check_result(2, "Hifens e pontos", ft_strtrim("...---sos---...", ".-"),
		"sos");

	// Teste 3: Set não encontrado (nada muda)
	check_result(3, "Set não existente", ft_strtrim("42 Tokyo", "xyz"),
		"42 Tokyo");

	// Teste 4: String composta apenas por caracteres do set
	check_result(4, "Tudo para remover", ft_strtrim("aaaaaaa", "a"), "");

	// Teste 5: String vazia
	check_result(5, "String vazia", ft_strtrim("", "abc"), "");

	// Teste 6: Set vazio (deve retornar uma cópia da string)
	check_result(6, "Set vazio", ft_strtrim("marjorie", ""), "marjorie");

	// Teste 7: Caracteres no meio não devem sair
	check_result(7, "Caracteres no meio", ft_strtrim("abaaba", "a"), "baab");

	printf("---------------------------\n");
}