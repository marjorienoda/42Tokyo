#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tests.h"

// Protótipo da sua função (para o compilador não reclamar)
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

// Função auxiliar que passaremos como parâmetro
// Ela transforma pares em MAIÚSCULAS e ímpares em minúsculas
char	my_test_transform(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c - 32);
	}
	else
	{
		if (c >= 'A' && c <= 'Z')
			return (c + 32);
	}
	return (c);
}

void	test_ft_strmapi(void)
{
	char	*str = "";
	char	*res;

	printf("--- Testando ft_strmapi ---\n");
	printf("Original:  %s\n", str);

	res = ft_strmapi(str, my_test_transform);

	if (res == NULL)
	{
		printf("Erro: A alocação falhou ou a função retornou NULL.\n");
		return ;
	}

	printf("Resultado: %s\n", res);

	// IMPORTANTE: Como sua função usou malloc, o teste deve liberar a memória
	free(res);
	printf("---------------------------\n\n");
}