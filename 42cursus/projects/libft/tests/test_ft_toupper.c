#include "tests.h"
#include <stdio.h>
#include <ctype.h>

void run_test(int c)
{
    int expected = toupper(c);
    int actual = ft_toupper(c);

    printf("Char: %c \n", c);
    printf("Expected: %d | Actual: %d \n", expected, actual);

    if((expected != 0 && actual != 0) || (expected == 0 && actual == 0))
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_toupper(void)
{
    printf("--- Testing ft_toupper ---\n");
    run_test('a');
    run_test('z');
    run_test('m');
    run_test('A');
    run_test('Z');
    run_test('0');
    run_test('9');
    run_test('!');
    run_test(' ');
    run_test('\n');
    run_test(0);
    run_test(127);

}