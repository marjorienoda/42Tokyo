#include "tests.h"
#include <stdio.h>
#include <string.h>

void run_test(char *str)
{
    int expected = strlen(str);
    int actual = ft_strlen(str);

    printf("Char: %s \n", str);
    printf("Expected: %d | Actual: %d \n", expected, actual);

    if((expected != 0 && actual != 0) || (expected == 0 && actual == 0))
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_strlen(void)
{
    printf("--- Testing ft_strlen ---\n");
    run_test("Hello");
    run_test("");
    run_test(" ");
    run_test("42Tokyo");
    run_test("For the character classification functions        ");
}