#include "ft_swap.h"
#include <stdio.h>

int main(void)
{
    int number = 20;
    int number_2 = 60;
    int *a = &number;
    int *b = &number_2;


    ft_swap(a, b);
    printf("number: %d \n", number);
    printf("number: %d", number_2);

}