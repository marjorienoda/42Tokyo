/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 06:42:41 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-04-23 06:42:41 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/*
	========== TESTE strlcat ==========
*/

// int	main(void)
// {
// 	const char	*src = "World";
// 	char		my_dst[50] = "Hello ";
// 	char		orig_dst[50] = "Hello ";
// 	size_t		size;
// 	size_t		my_result;
// 	size_t		original_res;

// 	size = 20;
// 	my_result = ft_strlcat(my_dst, src, size);
// 	original_res = strlcat(orig_dst, src, size);
// 	if (my_result != original_res)
// 	{
// 		printf("❌ Falha no Retorno! Esperado: %zu, Obtido: %zu\n", original_res,
// 			my_result);
// 	}
// 	else if (strcmp(my_dst, orig_dst) != 0)
// 	{
// 		printf("❌ Falha no Conteúdo! Esperado: '%s', Obtido: '%s'\n", orig_dst,
// 			my_dst);
// 	}
// 	else
// 	{
// 		printf("✅ Teste ok!\n");
// 		printf("Conteúdo: '%s' | Retorno: %zu\n", my_dst, my_result);
// 	}
// 	return (0);
// }

/*
	========== TESTE strchr ==========
*/
// int	main(void)
// {
// 	const char	*s = "Marjorie Noda Tamura";
// 	char		c;
// 	const char	*original_res;
// 	const char	*my_result;

// 	c = '\0';
// 	original_res = strchr(s, c);
// 	my_result = ft_strchr(s, c);
// 	if (my_result != original_res)
// 	{
// 		printf("❌ Falha no Retorno! Esperado: %s, Obtido: %s\n", original_res,
// 			my_result);
// 	}
// 	else
// 	{
// 		printf("✅ Teste ok!\n");
// 		printf("Obtido: %ld\n", my_result - s);
// 		printf("Esperado: %ld\n", original_res - s);
// 	}
// 	return (0);
// }

/*
	========== TESTE strrchr ==========
*/

// void	testar_strrchr(char *str, int c)
// {
// 	char	*orig;
// 	char	*my_result;

// 	orig = strrchr(str, c);
// 	my_result = ft_strrchr(str, c);
// 	if (orig == my_result)
// 	{
// 		printf("✅ Teste OK: '%s', char: '%c' (%d)\n", str, c, c);
// 	}
// 	else
// 	{
// 		printf("❌ Teste falhou: '%s', char: '%c'\n", str, c);
// 		printf("  Esperado: %p, Obtido: %p\n", (void *)orig, (void *)my_result);
// 	}
// }

// int	main(void)
// {
// 	// 1. Caso padrão: múltiplas ocorrências
// 	testar_strrchr("banana", 'a');

// 	// 2. Única ocorrência no fim
// 	testar_strrchr("hello", 'o');

// 	// 3. Caractere não encontrado
// 	testar_strrchr("corinthians", 'z');

// 	// 4. Busca pelo caractere nulo (Comportamento crucial!)
// 	// strrchr deve retornar o ponteiro para o '\0' da string
// 	testar_strrchr("teste", '\0');

// 	// 5. String vazia buscando caractere
// 	testar_strrchr("", 'x');

// 	// 6. String vazia buscando '\0'
// 	testar_strrchr("", '\0');

// 	return (0);
// }

/*
	========== TESTE strncmp ==========
*/

// void	testar(const char *s1, const char *s2, size_t n)
// {
// 	int	res_orig;
// 	int	res_sua;
// 	int	ok;

// 	res_orig = strncmp(s1, s2, n);
// 	res_sua = ft_strncmp(s1, s2, n);
// 	// Normalizando os retornos para facilitar a comparação (alguns sistemas retornam
// 	// -1/1, outros a diferença ASCII)
// 	ok = (res_orig == res_sua) || (res_orig > 0 && res_sua > 0) || (res_orig < 0
// 			&& res_sua < 0);
// 	printf("s1: \"%s\" | s2: \"%s\" | n: %zu\n", s1, s2, n);
// 	if (ok)
// 		printf("  ✅ Teste OK: Original: %d | Sua: %d\n", res_orig, res_sua);
// 	else
// 		printf("  ❌ Teste falhou: Original: %d | Sua: %d\n", res_orig, res_sua);
// 	printf("------------------------------------------\n");
// }

// int	main(void)
// {
// 	// 1. Strings iguais, n cobre tudo
// 	testar("abc", "abc", 3);

// 	// 2. Strings iguais, n é menor que o tamanho
// 	testar("abcdef", "abcxyz", 3);

// 	// 3. Diferença no primeiro caractere
// 	testar("Zbc", "abc", 3);

// 	// 4. s1 menor que s2 (ASCII)
// 	testar("testa", "teste", 10);

// 	// 5. Comparação com string vazia
// 	testar("", "algo", 1);

// 	// 6. n é zero (deve sempre retornar 0)
// 	testar("abc", "xyz", 0);

// 	// 7. Caractere nulo no meio da string (deve parar no \0)
// 	testar("abc\0def", "abc\0xyz", 10);

// 	// 8. Teste de sinal (importante: tratar como unsigned char)
// 	testar("\200", "\0", 1); // \200 é um valor alto se for unsigned

// 	return (0);
// }

/*
	========== TESTE strnstr ==========
*/

// char	*ft_strnstr(const char *big, const char *little, size_t len);

// void	run_test(const char *big, const char *little, size_t len)
// {
// 	char	*expected;
// 	char	*actual;

// 	expected = strnstr(big, little, len);
// 	actual = ft_strnstr(big, little, len);
// 	if (expected == actual)
// 	{
// 		printf("✅ PASS: big=\"%s\", little=\"%s\", len=%zu\n", big, little,
// 			len);
// 	}
// 	else
// 	{
// 		printf("❌ FAIL: big=\"%s\", little=\"%s\", len=%zu\n", big, little,
// 			len);
// 		printf("   Expected: %p (%s)\n", expected,
// 			expected ? expected : "NULL");
// 		printf("   Actual:   %p (%s)\n", actual, actual ? actual : "NULL");
// 	}
// }

// int	main(void)
// {
// 	printf("Starting strnstr verification...\n\n");

// 	// Standard cases
// 	run_test("Hello World", "World", 11);
// 	run_test("Hello World", "Hello", 5);

// 	// Empty needle
// 	run_test("Hello", "", 5);

// 	// Length restrictions
// 	run_test("Hello World", "World", 5);
// 	// Should be NULL (World starts at index 6)
// 	run_test("Hello World", "World", 10);
// 	// Should be NULL (Only searches up to index 9)

// 	// Not found
// 	run_test("Searching for something", "Nothing", 25);

// 	// Length is 0
// 	run_test("Anything", "Any", 0);

// 	// Needle longer than haystack
// 	run_test("Short", "Longer than haystack", 20);

// 	// Hidden match after \0
// 	run_test("Hidden\0Match", "Match", 12);

// 	return (0);
// }

/*
	========== TESTE atoi ==========
*/

// void	run_test(const char *input)
// {
// 	int	expected;
// 	int	actual;

// 	expected = atoi(input);
// 	actual = ft_atoi(input);
// 	if (expected == actual)
// 	{
// 		printf("✅ PASS: input=\"%s\" | Result: %d\n", input, actual);
// 	}
// 	else
// 	{
// 		printf("❌ FAIL: input=\"%s\"\n", input);
// 		printf("   Expected: %d\n", expected);
// 		printf("   Actual:   %d\n", actual);
// 	}
// }

// int	main(void)
// {
// 	printf("Starting atoi verification...\n\n");

// 	// Basic cases
// 	run_test("42");
// 	run_test("0");
// 	run_test("123456");

// 	// Signs
// 	run_test("-42");
// 	run_test("+42");
// 	run_test("--42"); // Should be 0
// 	run_test("+-42"); // Should be 0

// 	// Whitespaces (spaces, tabs, newlines, etc.)
// 	run_test("   42");
// 	run_test("\t\n\v\f\r 42");

// 	// Mixed characters
// 	run_test("42nd street");
// 	run_test("hello 42"); // Should be 0
// 	run_test("42 24");    // Should be 42

// 	// Limits
// 	run_test("2147483647");  // INT_MAX
// 	run_test("-2147483648"); // INT_MIN

// 	// Empty/Only whitespace
// 	run_test("");
// 	run_test("   ");

// 	return (0);
// }

/*
	========== TESTE memset ==========
*/

// void	test_memset(void)
// {
// 	char	buffer1[10] = "AAAAAAAAAA";
// 	char	buffer2[10] = "AAAAAAAAAA";

// 	// Teste 1: Básico
// 	ft_memset(buffer1, 'B', 5);
// 	memset(buffer2, 'B', 5);
// 	if (memcmp(buffer1, buffer2, 10) == 0)
// 		printf("Teste 1 (Básico): Passou!\n");
// 	else
// 		printf("Teste 1 (Básico): Falhou!\n");
// 	// Teste 2: n = 0
// 	ft_memset(buffer1, 'C', (0));
// 	memset(buffer2, 'C', (0));
// 	if (memcmp(buffer1, buffer2, 10) == 0)
// 		printf("Teste 2 (n=0): Passou!\n");
// 	else
// 		printf("Teste 2 (n=0): Falhou!\n");
// }

// int	main(void)
// {
// 	test_memset();
// 	return (0);
// }

/*
	========== TESTE bzero ==========
*/

// void	test_bzero(void)
// {
// 	char	buffer1[15];
// 	char	buffer2[15];
// 	int		i;
// 	int		fail;

// 	// Preparação dos buffers
// 	printf("### Iniciando Testes: ft_bzero ###\n\n");
// 	// --- TESTE 1: Limpeza Parcial ---
// 	// Enchemos com 'A' e limpamos os primeiros 5
// 	memset(buffer1, 'A', 14);
// 	buffer1[14] = '\0';
// 	memset(buffer2, 'A', 14);
// 	buffer2[14] = '\0';
// 	ft_bzero(buffer1, 5);
// 	bzero(buffer2, 5);
// 	if (memcmp(buffer1, buffer2, 15) == 0)
// 		printf("[OK] Teste 1: Limpeza parcial (5 bytes)\n");
// 	else
// 		printf("[ERRO] Teste 1: Os buffers estao diferentes!\n");
// 	// --- TESTE 2: n = 0 ---
// 	// Nada deve mudar no buffer
// 	memset(buffer1, 'B', 14);
// 	buffer1[14] = '\0';
// 	memset(buffer2, 'B', 14);
// 	buffer2[14] = '\0';
// 	ft_bzero(buffer1, 0);
// 	bzero(buffer2, (0));
// 	if (memcmp(buffer1, buffer2, 15) == 0)
// 		printf("[OK] Teste 2: n = 0 (Nenhuma alteracao)\n");
// 	else
// 		printf("[ERRO] Teste 2: ft_bzero alterou algo com n=0!\n");
// 	// --- TESTE 3: Limpeza Total ---
// 	ft_bzero(buffer1, 15);
// 	bzero(buffer2, 15);
// 	fail = 0;
// 	for (i = 0; i < 15; i++)
// 	{
// 		if (buffer1[i] != 0)
// 			fail = 1;
// 	}
// 	if (!fail && memcmp(buffer1, buffer2, 15) == 0)
// 		printf("[OK] Teste 3: Limpeza total do buffer\n");
// 	else
// 		printf("[ERRO] Teste 3: Falha ao zerar buffer completo\n");
// }

// int	main(void)
// {
// 	test_bzero();
// 	return (0);
// }

/*
	========== TESTE memcpy ==========
*/

// void	test_memcpy(void)
// {
// 	int		src_int[3] = {42, 100, -500};
// 	int		dest_int1[3];
// 	int		dest_int2[3];
// 	char	src_str[] = "0123456789";
// 	char	dest_str1[11] = "AAAAAAAAAA";
// 	char	dest_str2[11] = "AAAAAAAAAA";
// 	char	b1[10];
// 	char	b2[10] = "Teste";
// 	void	*ret;
// 	char	b3[5] = "AAAA";
// 	char	b4[5] = "BBBB";

// 	printf("### Iniciando Testes Avançados: ft_memcpy ###\n\n");
// 	// --- TESTE 1: Tipos de dados diferentes (Inteiros) ---
// 	ft_memcpy(dest_int1, src_int, sizeof(int) * 3);
// 	memcpy(dest_int2, src_int, sizeof(int) * 3);
// 	if (memcmp(dest_int1, dest_int2, sizeof(int) * 3) == 0)
// 		printf("[OK] Teste 1: Array de inteiros copiado corretamente.\n");
// 	else
// 		printf("[ERRO] Teste 1: Falha ao copiar inteiros.\n");
// 	// --- TESTE 2: Copiar parte de uma string (Off-set) ---
// 	// Copia "456" para o meio do buffer
// 	ft_memcpy(dest_str1 + 3, src_str + 4, 3);
// 	memcpy(dest_str2 + 3, src_str + 4, 3);
// 	if (memcmp(dest_str1, dest_str2, 11) == 0)
// 		printf("[OK] Teste 2: Cópia com offsets (meio do buffer).\n");
// 	else
// 		printf("[ERRO] Teste 2: Falha no offset. Resultado: %s\n", dest_str1);
// 	// --- TESTE 3: Verificação do Valor de Retorno ---
// 	ret = ft_memcpy(b1, b2, 5);
// 	if (ret == (void *)b1)
// 		printf("[OK] Teste 3: Retornou o ponteiro 'dest' corretamente.\n");
// 	else
// 		printf("[ERRO] Teste 3: O retorno não é igual ao endereço de destino!\n");
// 	// --- TESTE 4: n = 0 ---
// 	ft_memcpy(b3, b4, 0);
// 	if (b3[0] == 'A')
// 		printf("[OK] Teste 4: n = 0 não alterou o destino.\n");
// 	else
// 		printf("[ERRO] Teste 4: n = 0 alterou a memória indevidamente.\n");
// 	// --- TESTE 5: Ambas as entradas NULL ---
// 	// De acordo com o comportamento da libc em sistemas modernos
// 	if (ft_memcpy(NULL, NULL, 5) == NULL)
// 		printf("[OK] Teste 5: Ambos NULL retorna NULL.\n");
// 	else
// 		printf("[ERRO] Teste 5: Falha ao lidar com ponteiros NULL.\n");
// }

// int	main(void)
// {
// 	test_memcpy();
// 	return (0);
// }

/*
	========== TESTE memmove ==========
*/

// void	run_test(char *test_name, char *dest, const char *src, size_t n)
// {
// 	char	dest_ft[50] = {0};
// 	int		diff;

// 	char dest_orig[50] = {0}; // Inicializa com zeros
// 	strcpy(dest_orig, dest);
// 	strcpy(dest_ft, dest);
// 	memmove(dest_orig, src, n);
// 	ft_memmove(dest_ft, src, n);
// 	// Compara byte a byte
// 	diff = memcmp(dest_orig, dest_ft, 50);
// 	if (diff == 0)
// 	{
// 		printf("[OK] %s\n", test_name);
// 	}
// 	else
// 	{
// 		printf("[FAIL] %s\n", test_name);
// 		printf("   Esperado (hex): ");
// 		for (int i = 0; i < 20; i++)
// 			printf("%02x ", (unsigned char)dest_orig[i]);
// 		printf("\n   Recebido (hex): ");
// 		for (int i = 0; i < 20; i++)
// 			printf("%02x ", (unsigned char)dest_ft[i]);
// 		printf("\n");
// 	}
// }

// int	main(void)
// {
// 	char buffer[50] = "abcdefghij";

// 	// 1. Cópia simples (sem sobreposição)
// 	run_test("Copia simples", buffer, "12345", 5);

// 	// 2. Sobreposição: Destino está ANTES da origem (dest < src)
// 	// "cdefg" copiado para o início de "abcdefg"
// 	run_test("Sobreposicao (dest < src)", buffer, buffer + 2, 5);

// 	// 3. Sobreposição: Destino está DEPOIS da origem (dest > src)
// 	// "abcde" copiado para o meio de "abcde..."
// 	run_test("Sobreposicao (dest > src)", buffer + 2, buffer, 5);

// 	return (0);
// }

/*
	========== TESTE toupper ==========
*/

// int	main(void)
// {
// 	char test_chars[] = {'a', 'z', 'A', 'Z', '5', '!', ' '};
// 	int i = 0;

// 	while (i < 7)
// 	{
// 		printf("Char: %c | Original: %c | Sua: %c\n", test_chars[i],
// 			toupper(test_chars[i]), ft_toupper(test_chars[i]));
// 		i++;
// 	}
// 	return (0);
// }

/*
	========== TESTE toupper ==========
*/

// int	main(void)
// {
// 	char test_chars[] = {'a', 'z', 'A', 'Z', '5', '!', ' '};
// 	int i = 0;

// 	while (i < 7)
// 	{
// 		printf("Char: %c | Original: %c | Sua: %c\n", test_chars[i],
// 			tolower(test_chars[i]), ft_tolower(test_chars[i]));
// 		i++;
// 	}
// 	return (0);
// }

/*
	========== TESTE memchr ==========
*/

// void	run_test(int id, const void *s, int c, size_t n)
// {
// 	void	*res_orig;
// 	void	*res_ft;

// 	res_orig = memchr(s, c, n);
// 	res_ft = ft_memchr(s, c, n);
// 	if (res_orig == res_ft)
// 	{
// 		printf("Teste %02d: [OK] (Ponteiro: %p)\n", id, res_ft);
// 	}
// 	else
// 	{
// 		printf("Teste %02d: [ERRO] -> Esperado: %p, Obtido: %p\n", id, res_orig,
// 			res_ft);
// 		printf("Valor obtido: %c \n", *(char *)res_ft);
// 		printf("Valor esperado: %c \n", *(char *)res_orig);
// 	}
// }

// int	main(void)
// {
// 	printf("=== Iniciando Testes Comparativos: memchr vs ft_memchr ===\n\n");

// 	char str[] = "Hello, World!";

// 	// Teste 1: Busca simples no meio da string
// 	run_test(1, str, 'W', strlen(str));

// 	// Teste 2: Busca de caractere que não existe
// 	run_test(2, str, 'z', strlen(str));

// 	// Teste 3: Busca pelo caractere nulo (terminador \0)
// 	// memchr deve encontrar o \0 se n permitir
// 	run_test(3, str, '\0', strlen(str) + 1);

// 	// Teste 4: Limite de n (caractere existe, mas está fora do alcance de n)
// 	run_test(4, str, 'o', 3); // 'o' está na pos 4, n=3 não deve achar

// 	// Teste 5: Primeiro caractere da string
// 	run_test(5, str, 'H', strlen(str));

// 	// Teste 6: Busca em memória com valores não-ASCII (unsigned char cast)
// 	unsigned char data[] = {10, 20, 30, 45, 60};
// 	run_test(6, data, 45, 5);

// 	// Teste 7: Busca de um valor int que estoura unsigned char (ex: 256 + 'W')
// 	// A memchr trata o caractere como (unsigned char)c
// 	run_test(7, str, 'W' + 256, strlen(str));

// 	// Teste 8: n igual a zero (não deve ler nada e retornar NULL)
// 	run_test(8, str, 'H', 0);

// 	printf("\n=== Testes Finalizados ===\n");
// 	return (0);
// }

/*
	========== TESTE memcmp ==========
*/

// void	run_test_cmp(int id, const char *msg, const void *s1, const void *s2,
// 		size_t n)
// {
// 	int	res_orig;
// 	int	res_ft;
// 	int	sign_orig;
// 	int	sign_ft;

// 	res_orig = memcmp(s1, s2, n);
// 	res_ft = ft_memcmp(s1, s2, n);
// 	sign_orig = (res_orig > 0) - (res_orig < 0);
// 	sign_ft = (res_ft > 0) - (res_ft < 0);
// 	printf("--- Teste %02d: %s ---\n", id, msg);
// 	printf("  Original: %d (Sinal: %d)\n", res_orig, sign_orig);
// 	printf("  Sua func: %d (Sinal: %d)\n", res_ft, sign_ft);
// 	if (sign_orig == sign_ft)
// 	{
// 		printf("  Resultado: [ OK ]\n\n");
// 	}
// 	else
// 	{
// 		printf("  Resultado: [ ERRO ] <--- Sinais diferentes!\n\n");
// 	}
// }

// int	main(void)
// {
// 	unsigned char	b1[] = {0xff, 0x00, 0x01};
// 	unsigned char	b2[] = {0x00, 0x01, 0x02};

// 	printf("=== COMPARATIVO MEMCMP ===\n\n");
// 	// 1. Strings exatamente iguais
// 	run_test_cmp(1, "Strings identicas", "abcde", "abcde", 5);
// 	// 2. Diferença no último caractere (s1 maior)
// 	run_test_cmp(2, "S1 maior que S2 (final)", "abcde", "abcdc", 5);
// 	// 3. Diferença no primeiro caractere (s1 menor)
// 	run_test_cmp(3, "S1 menor que S2 (inicio)", "zbcde", "abcde", 1); // Ops,
// 																		// s1 é maior aqui
// 	// 4. Teste de limite 'n' (iguais até n, mas diferentes depois)
// 	run_test_cmp(4, "Iguais ate n=3, diferentes depois", "abcdef", "abcXYZ", 3);
// 	// 5. n = 0 (deve retornar 0 independente do conteúdo)
// 	run_test_cmp(5, "n igual a zero", "aaaaa", "bbbbb", 0);
// 	// 6. Teste com valores unsigned char (importante!)
// 	// O valor 255 (0xFF) é maior que 0 se tratado como unsigned.
// 	run_test_cmp(6, "Tratamento de Unsigned Char (0xFF vs 0x00)", b1, b2, 1);
// 	// 7. Strings com \0 no meio (memcmp NÃO para no \0)
// 	run_test_cmp(7, "Presenca de \\0 no meio", "abc\0def", "abc\0XYZ", 7);
// 	return (0);
// }

/*
	========== TESTE calloc ==========
*/

static void	test_zero_allocation(void)
{
	void	*ptr_ft;
	void	*ptr_orig;

	printf("--- Teste: nmemb=0, size=0 (Regra do Ponteiro Unico) ---\n");
	ptr_ft = ft_calloc(0, 0);
	ptr_orig = calloc(0, 0);
	printf("  Original calloc(0,0): %p\n", ptr_orig);
	printf("  Sua ft_calloc(0,0):   %p\n", ptr_ft);
	if (ptr_ft != NULL)
		printf("  Resultado: [ OK ] (Ponteiro valido retornado)\n");
	else
		printf("  Resultado: [ ERRO ] (Retornou NULL para tamanho 0)\n");
	free(ptr_ft);
	free(ptr_orig);
	printf("  Free executado sem crashes.\n\n");
}

/*
** Testa se a memoria comum esta zerada
*/
static void	test_memory_zero(size_t n, size_t size)
{
	unsigned char	*p;
	size_t			i;
	size_t			total;

	total = n * size;
	p = (unsigned char *)ft_calloc(n, size);
	printf("--- Teste: %zu elementos de %zu bytes ---\n", n, size);
	if (!p)
	{
		printf("  Resultado: [ ERRO ] Falha na alocacao\n\n");
		return ;
	}
	i = 0;
	while (i < total)
	{
		if (p[i] != 0)
		{
			printf("  Resultado: [ ERRO ] Byte na pos %zu nao e zero!\n\n", i);
			free(p);
			return ;
		}
		i++;
	}
	printf("  Resultado: [ OK ] Toda a memoria esta zerada.\n\n");
	free(p);
}

int	main(void)
{
	printf("=== INICIANDO TESTES CALLOC (PADRAO 42) ===\n\n");
	// Teste da regra especifica de nmemb/size = 0
	test_zero_allocation();
	// Testes de integridade de dados
	test_memory_zero(10, sizeof(int));
	test_memory_zero(1, 1);
	test_memory_zero(100, 1);
	printf("=== TESTES FINALIZADOS ===\n");
	return (0);
}

/*
	========== TESTE strdup ==========
*/

// static void	run_test(int id, const char *original)
// {
// 	char	*copy_orig;
// 	char	*copy_ft;

// 	copy_orig = strdup(original);
// 	copy_ft = ft_strdup(original);
// 	printf("Teste %d [%s]: ", id, original);
// 	if (!copy_ft)
// 	{
// 		printf("ERRO: Retornou NULL\n");
// 		free(copy_orig);
// 		return ;
// 	}
// 	if (strcmp(copy_orig, copy_ft) == 0 && copy_orig != copy_ft)
// 		printf("SUCESSO (Conteúdo igual e endereços diferentes)\n");
// 	else if (copy_orig == copy_ft)
// 		printf("FALHA (Mesmo endereço de memória)\n");
// 	else
// 		printf("FALHA (Conteúdo diferente)\n");
// 	free(copy_orig);
// 	free(copy_ft);
// }

// int	main(void)
// {
// 	printf("--- Iniciando Testes ft_strdup ---\n");

// 	// Teste 1: String comum
// 	run_test(1, "42 Sao Paulo / Brasil");

// 	// Teste 2: String vazia
// 	run_test(2, "");

// 	// Teste 3: String com caracteres especiais
// 	run_test(3, "Hello\tWorld\n!");

// 	// Teste 4: String longa
// 	run_test(4, "Uma string consideravelmente longa para testar malloc.");

// 	printf("--- Fim dos Testes ---\n");
// 	return (0);
// }