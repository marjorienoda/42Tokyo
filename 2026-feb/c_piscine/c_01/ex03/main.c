#include "ft_div_mod.h"
#include <stdio.h>

int main(void)
{
    int a = 31;
    int b = 4;
    int div_result = 0;
    int mod_result = 0;

    int *div =  &div_result;
    int *mod =  &mod_result;

    ft_div_mod(a, b, div, mod);
    printf("number a: %d \n", a);
    printf("number b: %d \n", b);
    printf("div result: %d \n", *div);
    printf("mod result: %d", *mod);


}