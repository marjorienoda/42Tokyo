#include "tests.h"
#include <stdio.h>
#include <string.h>

void run_test(char *d_ft, char *d_orig, const char *s, size_t n)
{
    // Executa ambas as funções
    ft_memcpy(d_ft, s, n);
    memcpy(d_orig, s, n);

    printf("Test: Copy %zu bytes from \"%s\"\n", n, s);
    printf("Expected: [%s] | Actual: [%s] ", d_orig, d_ft);

    // Compara o conteúdo dos buffers após a operação
    if (memcmp(d_ft, d_orig, 15) == 0)
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_memcpy(void)
{
    printf("--- Testing ft_memcpy ---\n");
    char str[] = "42Tokyo";
    char dest_ft1[15] = {0};
    char dest_orig1[15] = {0};
    run_test(dest_ft1, dest_orig1, str, 8);

    char str1[] = "ABCDEFGHIJ";
    char dest_ft2[15] = "XXXXXXXXXX";
    char dest_orig2[15] = "XXXXXXXXXX";
    run_test(dest_ft2, dest_orig2, str1, 9);

    char str2[] = "banananananana";
    char dest_ft3[15] = "apple";
    char dest_orig3[15] = "apple";
    run_test(dest_ft3, dest_orig3, str2, 0);

}