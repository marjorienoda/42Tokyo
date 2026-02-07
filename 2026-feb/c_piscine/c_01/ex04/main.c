#include "ft_ultimate_div_mod.h"
#include <stdio.h>

int main(void)
{
    int number = 25;
    int number_2 = 5;

    int *a = &number;
    int *b = &number_2;

    ft_ultimate_div_mod(a, b);
    printf("number: %d \n", number);
    printf("number 2: %d \n", number_2);
    printf("div result: %d \n", *a);
    printf("mod result: %d \n", *b);
    return 0;
}