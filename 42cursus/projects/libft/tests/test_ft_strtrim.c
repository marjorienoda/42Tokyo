#include "tests.h"
#include <stdio.h>
#include <string.h>

// static void	run_test(char const *s1, char const *set, char *expected,
// 		char *test_name)
// {
// 	char	*actual;
// 	size_t	expected_len;

// 	expected_len = ft_strlen(expected);
// 	actual = ft_strtrim(s1, set);
// 	printf("Test: %s  \n", test_name);
// 	if (expected == NULL && actual == NULL)
// 		printf("✅ SUCCESS (NULL)\n");
// 	else
// 	{
// 		if (ft_memcmp(expected, actual, expected_len) == 0)
// 			printf("✅ SUCCESS: content matches \n");
// 		else
// 			printf("❌ FAILED\n Error NULL \n");
// 	}
// 	if (actual)
// 		free(actual);
// 	printf("---------------------------\n");
// }

// void	test_ft_strtrim(void)
// {
// 	printf("--- Testing ft_strtrim ---\n");

// 	run_test("   hello world   ", " ", "hello world", "Spaces");

// 	run_test("...---sos---...", ".-", "sos", "Specials characters");

// 	run_test("42 Tokyo", "xyz", "42 Tokyo", "Set doesnt exist");

// 	run_test("aaaaaaa", "a", "", "Removes everything");

// 	run_test("", "abc", "", "String empty");

// 	run_test("marjorie", "", "marjorie", "Set empyt");

// 	run_test("abaaba", "a", "baab", "Characters in the middle");

// 	run_test("xxxz  test with x and z and x .  zx  xx z", "z x", "	",
// 		"Characters in the middle");
// }

#ifdef __APPLE__
# include <malloc/malloc.h>
# define MALLOC_SIZE(ptr) malloc_size(ptr)
#else
# include <malloc.h>
# define MALLOC_SIZE(ptr) malloc_usable_size(ptr)
#endif

char	*ft_strtrim(char const *s1, char const *set);

void	test_trim_allocation(char *s1, char *set)
{
	char	*res;
	size_t	real_str_len;
	size_t	allocated_size;

	res = ft_strtrim(s1, set);
	if (!res)
	{
		printf("❌ Erro: Retornou NULL\n");
		return ;
	}
	real_str_len = strlen(res) + 1;    // O que deveria ser alocado (+1 do \0)
	allocated_size = MALLOC_SIZE(res); // O que você realmente alocou
	printf("S1: [%s] | SET: [%s]\n", s1, set);
	printf("RESULTADO: [%s]\n", res);
	printf("BYTES NECESSÁRIOS: %zu\n", real_str_len);
	printf("BYTES ALOCADOS:    %zu\n", allocated_size);
	// Verificação de desperdício (considerando pequena margem de alinhamento do SO)
	if (allocated_size > real_str_len + 8)
		printf("❌ FALHA: Você alocou memória demais! (Desperdício detectado)\n");
	else
		printf("✅ SUCESSO: Alocação otimizada.\n");
	printf("--------------------------------------------------\n");
	free(res);
}

int	main(void)
{
	printf("--- TESTE DE ALOCAÇÃO FT_STRTRIM ---\n\n");

	// Caso 1: Espaços no final
	test_trim_allocation("ab cd  f    ", " ");

	// Caso 6 da Francinette: Muitos caracteres no set nas extremidades
	test_trim_allocation("xxxz  test with x and z and x .  zx  xx z", "z x");

	// Caso 8 da Francinette: Caracteres especiais
	test_trim_allocation(".teste, bla ,.,.", ",.");

	return (0);
}