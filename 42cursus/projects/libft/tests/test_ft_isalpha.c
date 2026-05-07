#include "tests.h"
#include <stdio.h>
#include <ctype.h>

void run_test(int c)
{
    int expected = isalpha(c);
    int actual = ft_isalpha(c);

    printf("Char: %c", c);
    printf("Expected: %d | Actual: %d", expected, actual);

    if((expected != 0 && actual != 0) || (expected == 0 && actual == 0))
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
    printf("------------------------------\n");
}

void test_ft_isalpha(void)
{
    printf("--- Testing ft_isalpha ---\n");
    run_test('Z');
    run_test('a');
    run_test('0');
    run_test('9');
    run_test('!');
    run_test('@');

    run_test(64);
    run_test(65);
    run_test(90);
    run_test(91);
    run_test(96);
    run_test(97);
    run_test(122);
    run_test(123);
}