unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i > 0)
	{
		// 1. Abre espaço no resultado empurrando os bits para a esquerda
		res = (res << 1);
		// 2. Pega o bit mais à direita do octet original e coloca no resultado
		res = res | (octet & 1);
		// 3. Empurra o octet original para a direita para processar o próximo bit
		octet = (octet >> 1);
		i--;
	}
	return (res);
}

#include <stdio.h> // Apenas para o printf de teste, no exame você não usaria
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet);

// Função auxiliar apenas para visualizarmos os bits no terminal
void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 7;
	while (i >= 0)
	{
		// Desloca o bit que queremos para a posição 0 e isola ele
		bit = (octet >> i) & 1;
		bit += '0'; // Transforma em caractere '0' ou '1'
		write(1, &bit, 1);
		i--;
	}
}

int	main(void)
{
	// Exemplo do enunciado: 0010 0110 (que é 38 em decimal)
	unsigned char teste = 0x26; // 0x26 é 38 em hexadecimal
	unsigned char resultado;

	resultado = reverse_bits(teste);

	printf("Original:  ");
	print_bits(teste);
	printf(" (Decimal: %d)\n", teste);

	printf("Invertido: ");
	print_bits(resultado);
	printf(" (Decimal: %d)\n", resultado);

	return (0);
}