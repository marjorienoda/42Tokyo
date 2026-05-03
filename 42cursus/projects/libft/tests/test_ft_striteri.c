#include "tests.h"
#include <stdio.h>
#include <ctype.h>

// Protótipo da sua função
void ft_striteri(char *s, void (*f)(unsigned int, char*));

// Função auxiliar para striteri
// Ela usa o ponteiro (char *) para modificar o caractere no local
void	my_test_iter_transform(unsigned int i, char *c)
{
	if (i % 2 == 0)
	{
		if (*c >= 'a' && *c <= 'z')
			*c = *c - 32; // Transforma em maiúscula acessando o valor no endereço
	}
	else
	{
		if (*c >= 'A' && *c <= 'Z')
			*c = *c + 32; // Transforma em minúscula
	}
}

void	test_ft_striteri(void)
{
	// Usamos um array char[] para que a memória seja editável
	char	str[] = "piscine 42";

	printf("--- Testando ft_striteri ---\n");
	printf("Original:  %s\n", str);

	// A função modifica a variável 'str' diretamente
	ft_striteri(str, my_test_iter_transform);

	printf("Resultado: %s\n", str);
	printf("Esperado:  PiScInE 42\n");
	printf("---------------------------\n\n");
}