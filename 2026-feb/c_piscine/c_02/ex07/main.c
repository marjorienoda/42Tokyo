#include "ft_strupcase.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char string_src[] = "oi mo€zinho? 64548";

    char *string_src_ptr = &string_src[0];

    char *result = ft_strupcase(string_src_ptr);

    while(*result != '\0')
    {
        write(1, result, 1);
        result++;
    }
    return 0;
    
}