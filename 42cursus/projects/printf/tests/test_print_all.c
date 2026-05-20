#include "tests.h"
#include <limits.h>

static void	print_result(int original, int actual)
{
	if (actual == original)
		printf("\033[0;32m✅ SUCCESS!\033[0m\n");
	else
		printf("\033[0;31m❌ FAILED! Original: %d | Actual: %d\033[0m\n",
			original, actual);
	printf("----------------------------------------\n");
}

void	test_print_all(void)
{
	int		orig;
	int		ft;
	char	*s2;

	s2 = "testing testing";
	// T1: Caracteres (%c) com estouro e normais
	printf("T1 (Orig):   [");
	fflush(stdout);
	orig = printf("Chars: %c %c %c", 'A', 0, 'z');
	printf("]\n");
	printf("T1 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Chars: %c %c %c", 'A', 0, 'z');
	printf("]");
	print_result(orig, ft);
	// T2: Strings (%s) com texto ao redor e NULL protegido
	printf("T2 (Orig):   [");
	fflush(stdout);
	orig = printf(" %s | %s | %s ", "42 Tokyo", "", (char *)NULL);
	printf("]\n");
	printf("T2 (Actual): [");
	fflush(stdout);
	ft = ft_printf(" %s | %s | %s ", "42 Tokyo", "", (char *)NULL);
	printf("]");
	print_result(orig, ft);
	// T3: Ponteiros (%p) de variáveis e nulos
	printf("T3 (Orig):   [");
	fflush(stdout);
	orig = printf("Ptrs: %p %p", (void *)s2, (void *)NULL);
	printf("]\n");
	printf("T3 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Ptrs: %p %p", (void *)s2, (void *)NULL);
	printf("]");
	print_result(orig, ft);
	// T4: Inteiros com sinal (%d e %i) e limites exatos
	printf("T4 (Orig):   [");
	fflush(stdout);
	orig = printf("Ints: %d %i %d", INT_MAX, INT_MIN, 0);
	printf("]\n");
	printf("T4 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Ints: %d %i %d", INT_MAX, INT_MIN, 0);
	printf("]");
	print_result(orig, ft);
	// T5: Inteiros sem sinal (%u) no limite máximo
	printf("T5 (Orig):   [");
	fflush(stdout);
	orig = printf("Unsigned: %u %u", UINT_MAX, 0);
	printf("]\n");
	printf("T5 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Unsigned: %u %u", UINT_MAX, 0);
	printf("]");
	print_result(orig, ft);
	// T6: Hexadecimais minúsculos (%x)
	printf("T6 (Orig):   [");
	fflush(stdout);
	orig = printf("Hex low: %x %x %x", 0, 42, INT_MAX);
	printf("]\n");
	printf("T6 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Hex low: %x %x %x", 0, 42, INT_MAX);
	printf("]");
	print_result(orig, ft);
	// T7: Hexadecimais maiúsculos (%X)
	printf("T7 (Orig):   [");
	fflush(stdout);
	orig = printf("Hex UP: %X %X %X", 0, 42, INT_MAX);
	printf("]\n");
	printf("T7 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Hex UP: %X %X %X", 0, 42, INT_MAX);
	printf("]");
	print_result(orig, ft);
	// T8: Símbolo de porcentagem puro (%%)
	printf("T8 (Orig):   [");
	fflush(stdout);
	orig = printf("%%%% -> 100%% OFF!!");
	printf("]\n");
	printf("T8 (Actual): [");
	fflush(stdout);
	ft = ft_printf("%%%% -> 100%% OFF!!");
	printf("]");
	print_result(orig, ft);
	// T9: MISTURA TOTAL (O caos que o revisor vai fazer)
	printf("T9 (Orig):   [");
	fflush(stdout);
	orig = printf("Mix: %c %s %p %d %u %x %%%%", '4', "two", (void *)16, -42,
			4242, 3735928559U);
	printf("]\n");
	printf("T9 (Actual): [");
	fflush(stdout);
	ft = ft_printf("Mix: %c %s %p %d %u %x %%%%", '4', "two", (void *)16, -42,
			4242, 3735928559U);
	printf("]");
	print_result(orig, ft);
}
