#include "tests.h"

static void	print_result(int original, int actual)
{
	if (actual == original)
		printf("\033[0;32m✅ SUCCESS!\033[0m\n");
	else
		printf("\033[0;31m❌ FAILED! Original: %d | Actual: %d\033[0m\n",
			original, actual);
	printf("----------------------------------------\n");
}

void	test_print_percent(void)
{
	int	orig;
	int	ft;

	// TEST 1: O caso padrão obrigatório do subject
	printf("Test 1 (Orig):   [");
	fflush(stdout);
	orig = printf("%%");
	printf("]\n");
	printf("Test 1 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%%");
	printf("]");
	print_result(orig, ft);
	// TEST 2: Dois símbolos seguidos (deve printar %%)
	printf("Test 2 (Orig):   [");
	fflush(stdout);
	orig = printf("%%%%");
	printf("]\n");
	printf("Test 2 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%%%%");
	printf("]");
	print_result(orig, ft);
	// TEST 3: Com texto antes e depois
	printf("Test 3 (Orig):   [");
	fflush(stdout);
	orig = printf("Desconto de 50%% hoje!");
	printf("]\n");
	printf("Test 3 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Desconto de 50%% hoje!");
	printf("]");
	print_result(orig, ft);
	// TEST 4: Espaços entre os símbolos
	printf("Test 4 (Orig):   [");
	fflush(stdout);
	orig = printf(" %% ");
	printf("]\n");
	printf("Test 4 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %% ");
	printf("]");
	print_result(orig, ft);
	// TEST 5: Vários símbolos seguidos (deve printar %%%)
	printf("Test 5 (Orig):   [");
	fflush(stdout);
	orig = printf("%%%%%%%%");
	printf("]\n");
	printf("Test 5 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%%%%%%%%");
	printf("]");
	print_result(orig, ft);
	// TEST 6: Misturado com outros formatos válidos
	printf("Test 6 (Orig):   [");
	fflush(stdout);
	orig = printf("%%d -> %d %%", 42);
	printf("]\n");
	printf("Test 6 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%%d -> %d %%", 42);
	printf("]");
	print_result(orig, ft);
	// TEST 7: Um
	// % sozinho no final da string (O seu código dá segfault/loop infinito?)
	printf("Test 7 (Orig):   [");
	fflush(stdout);
	orig = printf("Teste %");
	printf("]\n");
	printf("Test 7 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Teste %");
	printf("]");
	print_result(orig, ft);
	// TEST 8: Apenas um % na string inteira
	printf("Test 8 (Orig):   [");
	fflush(stdout);
	orig = printf("%");
	printf("]\n");
	printf("Test 8 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%");
	printf("]");
	print_result(orig, ft);
}
