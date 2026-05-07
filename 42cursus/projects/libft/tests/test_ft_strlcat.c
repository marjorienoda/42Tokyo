#include "tests.h"
#include <stdio.h>
#include <string.h>

size_t strlcat(char *dst, const char *src, size_t size);

void run_test(char *d_ft, char *d_orig, const char *s, size_t sz, char *desc)
{
    printf("Test: %s (size=%zu)\n", desc, sz);
    
    size_t ret_ft = ft_strlcat(d_ft, s, sz);
    size_t ret_orig = strlcat(d_orig, s, sz);

    printf("Expected Dest: [%s] | Actual Dest: [%s]\n", d_orig, d_ft);
    printf("Expected Ret:  %zu  | Actual Ret:  %zu\n", ret_orig, ret_ft);

    if (ret_ft == ret_orig && strcmp(d_ft, d_orig) == 0)
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_strlcat(void)
{
    printf("--- Testing ft_strlcat ---\n");

    char df1[20] = "Hello";
    char do1[20] = "Hello";
    run_test(df1, do1, " World", 20, "Enough space");

    char df2[10] = "Marjorie";
    char do2[10] = "Marjorie";
    run_test(df2, do2, "Yumie Noda Tamura", 10, "Truncate");

    char df3[10] = "banana";
    char do3[10] = "banana";
    run_test(df3, do3, " apple", 4, "Size < dst_len");

    char df4[10] = "bananas";
    char do4[10] = "bananas";
    run_test(df4, do4, "apples", 7, "Size = dst_len");
}