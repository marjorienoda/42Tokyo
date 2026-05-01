#include "tests.h"
#include <stdio.h>
#include <string.h>

// Função auxiliar para imprimir o array e dar free
static void	print_and_free(char **res)
{
	int	i;

	if (!res)
	{
		printf("Resultado: NULL\n");
		return ;
	}
	i = 0;
	while (res[i])
	{
		printf("  [%d]: \"%s\"\n", i, res[i]);
		printf("  [%d]: Endereco: %p | Conteudo: %s\n", i, (void *)res[i],
			res[i]);
		free(res[i]); // Libera cada palavra
		i++;
	}
	free(res); // Libera o array de ponteiros
}

void	test_ft_split(void)
{
	char **res;

	// Caso 1: Frase normal com espaços variados
	printf("Teste 1: '  Ola  tudo  bem  ', sep: ' '\n");
	res = ft_split("  Ola  tudo  bem  ", ' ');
	print_and_free(res);
	printf("\n");

	// Caso 2: Sem separadores
	printf("Teste 2: '42Tokyo', sep: '-'\n");
	res = ft_split("42Tokyo", '-');
	print_and_free(res);
	printf("\n");

	// Caso 3: Apenas separadores
	printf("Teste 3: '-------', sep: '-'\n");
	res = ft_split("-------", '-');
	print_and_free(res);
	printf("\n");

	// Caso 4: String vazia
	printf("Teste 4: '', sep: ' '\n");
	res = ft_split("", ' ');
	print_and_free(res);
	printf("\n");

	// Caso 5: Separador é o caractere nulo (raro, mas bom testar)
	printf("Teste 5: 'Abacate', sep: '\\0'\n");
	res = ft_split("Abacate", '\0');
	print_and_free(res);
}