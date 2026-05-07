#include "tests.h"
#include <stdio.h>
#include <string.h>

void run_test(char *d_ft, char *d_orig, const char *s, size_t n)
{
    ft_memmove(d_ft, s, n);
    memmove(d_orig, s, n);

    printf("Test: Moving %zu bytes \n", n);
    printf("Expected: [%s] | Actual: [%s] \n", d_orig, d_ft);

    if (memcmp(d_ft, d_orig, 20) == 0)
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_memmove(void)
{
    printf("--- Testing ft_memmove ---\n");
    char str1[] = "12345";
    char dest_ft1[20] = "ABCDE";
    char dest_orig1[20] = "ABCDE";
    run_test(dest_ft1, dest_orig1, str1, 5);

    char overlap_ft2[20] = "abcde";
    char overlap_orig2[20] = "abcde";
    ft_memmove(overlap_ft2 + 1, overlap_ft2, 3);
    memmove(overlap_orig2 + 1, overlap_orig2, 3);
    
    printf("Test: Overlap (dest > src)\n");
    printf("Expected: [%s] | Actual: [%s] ", overlap_orig2, overlap_ft2);
    if (strcmp(overlap_ft2, overlap_orig2) == 0) printf("✅ SUCCESS\n");
    else printf("❌ FAILED\n");
    printf("------------------------------\n");

    char overlap_ft3[20] = "abcde";
    char overlap_orig3[20] = "abcde";
    ft_memmove(overlap_ft3, overlap_ft3 + 1, 3);
    memmove(overlap_orig3, overlap_orig3 + 1, 3);

    printf("Test: Overlap (dest < src)\n");
    printf("Expected: [%s] | Actual: [%s] ", overlap_orig3, overlap_ft3);
    if (strcmp(overlap_ft3, overlap_orig3) == 0) printf("✅ SUCCESS\n");
    else printf("❌ FAILED\n");
}