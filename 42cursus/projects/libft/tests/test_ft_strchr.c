#include "tests.h"
#include <stdio.h>
#include <string.h>

void run_test(const char *s, int c, char *desc)
{
    char *expected = strchr(s, c);
    char *actual = ft_strchr(s, c);

    printf("Test: %s \n", desc);
    if(expected == actual)
        printf("✅ SUCCESS \n" );
    else
    {
        printf("❌ FAILED\n");
    }
    printf("------------------------------\n");
}

void test_ft_strchr(void)
{
    printf("--- Testing ft_strchr ---\n");
    run_test("Marjorie", 'j', "Find the character");

	run_test("banana", 'a', "First occurance");

	run_test("Marjorie", 'z', "Dont exist");

	run_test("42Tokyo", '\0', "null terminator ('\\0')");

	run_test("Tokyo", 'T', "First character");

	run_test("Hello!", '!', "Last character");

	run_test("test", 'e' + 256, "nt overflow (cast to char)");

	run_test("", 'A', "empty string");

}