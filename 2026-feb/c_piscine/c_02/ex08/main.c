#include "ft_strlowcase.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char string_src[] = "OI MO€zinho? 64548";

    char *string_src_ptr = &string_src[0];

    char *result = ft_strlowcase(string_src_ptr);

    while(*result != '\0')
    {
        write(1, result, 1);
        result++;
    }
    return 0;
    
}