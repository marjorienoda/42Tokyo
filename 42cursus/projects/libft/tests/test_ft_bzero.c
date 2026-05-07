#include "tests.h"
#include <stdio.h>

void run_test(size_t size, size_t n)
{
    char str[size];
    size_t i;
    int sucess = 1;

    ft_memset(str, 'A', size);
    ft_bzero(str, n);

    i = 0;
    while(i < n)
    {
        if(str[i] != '\0')
            sucess = 0;
        i++;
    }
    if(sucess)
        printf("✅ SUCCESS\n");
    else
        printf("❌ FAILED\n");
}

void test_ft_bzero(void)
{
    printf("--- Testing ft_bzero ---\n");
    run_test(10, 5); 
    run_test(10, 10);
    run_test(10, 0);
}