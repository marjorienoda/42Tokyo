unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4) | (octet >> 4));
}

#include <stdio.h>

int	main(void)
{
	unsigned char c = 0x41; // 0100 0001 (Decimal 65, Letra 'A')
	unsigned char result;

	result = swap_bits(c);

	// Exibe em hexadecimal para facilitar a visualização
	printf("Original: %02x\n", c);      // Saída: 41
	printf("Trocado:  %02x\n", result); // Saída: 14 (0001 0100)
	return (0);
}