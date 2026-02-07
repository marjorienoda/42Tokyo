#include "ft_strlen.h"
#include <stdio.h>

int main(void)
{
    char words[] = "marjorie yumie noda tamura!";
    char *str = words;

    int result = ft_strlen(str);
    printf("result counting: %d" , result);
    return 0;
}