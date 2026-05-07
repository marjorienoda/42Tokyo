#include "tests.h"
#include <stdio.h>
#include <string.h>

void run_test(char *str_ft, char *str_orig, int c, size_t n)
{
    // Executa ambas as funções
    ft_memset(str_ft, c, n);
    memset(str_orig, c, n);

    printf("Test: Fill %zu bytes with '%c'\n", n, c);
    printf("Expected: [%s] | Actual: [%s] \n", str_orig, str_ft);

    // Compara o conteúdo dos buffers após a operação
    if (memcmp(str_ft, str_orig, 15) == 0)
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_memset(void)
{
    printf("--- Testing ft_memset ---\n");
    char b1[15] = "AAAAA";
    char b2[15] = "AAAAA";
    run_test(b1, b2, 'B', 3);

    char b3[15] = {0};
    char b4[15] = {0};
    run_test(b3, b4, 'Z', 5);

    // Teste 3: n = 0 (Não deve alterar nada)
    char b5[15] = "42Tokyo";
    char b6[15] = "42Tokyo";
    run_test(b5, b6, 'X', 0);
}