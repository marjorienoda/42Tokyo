char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;
    
    if (to_find[0] == '\0')
        return (str);
    i = 0;
    while (str[i] != '\0')
    {
        j = 0;
        while(to_find[j] != '\0' && str[i + j] != '\0'
                && str[i + j] == to_find[j])
        {
            j++;
        }
        if (to_find[j] == '\0')
            return (&str[i]);
        i++;
    }
    return (0);
}

#include <stdio.h>

void run_test(char *str, char *to_find, char *expected)
{
    char *result = ft_strstr(str, to_find);

    printf("Searching for '%s' in '%s'\n", to_find, str);
    printf("Expected result: '%s'\n", expected ? expected : "NULL");
    printf("Actual result: '%s'\n", result ? result : "NULL");

    if (result == expected
        || (result && expected && result - str == expected - str))
        printf("TEST PASS\n\n");
    else
        printf("TEST FAIL\n\n");
}

int main(void)
{
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    char str3[] = "42 is awesome";
    char str4[] = "";
    char str5[] = "abcd";
    char str6[] = "c";
    char str7[] = "!";

    run_test(str1, "world", str1 + 7);
    run_test(str1, "Hello", str1);
    run_test(str1, "!", str1 + 12);
    run_test(str2, "Hello, world!", str2);
    run_test(str3, "", str3);
    run_test(str1, "notfound", NULL);
    run_test(str4, "a", NULL);
    run_test(str4, "", str4);
    run_test(str5, "c", str5 + 2);
    run_test(str5, "d", str5 + 3);
    run_test(str5, "z", NULL);
    run_test(str5, str6, str5 + 2);
    run_test(str1, str7, str1 + 12);
    run_test("Hel", "Hello", NULL);

    return (0);
}