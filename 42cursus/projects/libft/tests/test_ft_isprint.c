#include "tests.h"
#include <stdio.h>
#include <ctype.h>

void run_test(int c)
{
    int expected = isprint(c);
    int actual = ft_isprint(c);

    printf("Char: %c \n", c);
    printf("Expected: %d | Actual: %d \n", expected, actual);

    if((expected != 0 && actual != 0) || (expected == 0 && actual == 0))
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_isprint(void)
{
    printf("--- Testing ft_isprint ---\n");
    run_test(0);
    run_test(9);
    run_test(31);
    run_test(32);
    run_test(65);
    run_test(126);
    run_test(127);
    run_test(128);
}