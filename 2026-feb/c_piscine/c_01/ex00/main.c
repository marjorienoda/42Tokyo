#include "ft_ft.h"
#include <stdio.h>

int main(void)
{
    int number = 0;
    int *nbr = &number;
    ft_ft(nbr);
    printf("%d", *nbr);
    return 0;
}