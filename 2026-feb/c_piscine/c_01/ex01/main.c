#include "ft_ultimate_ft.h"
#include <stdio.h>

int main(void)
{
    int number = 0;
    int *ptr9 = &number;
    int **ptr8 = &ptr9;
    int ***ptr7 = &ptr8;
    int ****ptr6 = &ptr7;
    int *****ptr5 = &ptr6;
    int ******ptr4 = &ptr5;
    int *******ptr3 = &ptr4;
    int ********ptr2 = &ptr3;
    int *********ptr1 = &ptr2;

    ft_ultimate_ft(ptr1);
    printf("%d", *********ptr1);
    return 0;

}