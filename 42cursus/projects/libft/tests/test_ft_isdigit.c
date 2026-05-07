#include "tests.h"
#include <stdio.h>
#include <ctype.h>

void run_test(int c)
{
    int expected = isdigit(c);
    int actual = ft_isdigit(c);

    printf("Char: %c \n", c);
    printf("Expected: %d | Actual: %d \n", expected, actual);

    if((expected != 0 && actual != 0) || (expected == 0 && actual == 0))
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_isdigit(void)
{
    printf("--- Testing ft_isdigit ---\n");
    run_test('Z');
    run_test('a');
    run_test('0');
    run_test('9');
    run_test('!');
    run_test('@');
    run_test('5');

}