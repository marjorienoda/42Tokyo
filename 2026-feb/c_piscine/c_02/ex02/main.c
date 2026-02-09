#include "ft_str_is_alpha.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char string_src[] = "Marjijori";

    char *string_src_ptr = &string_src[0];

    int result = ft_str_is_alpha(string_src_ptr);

    printf("%d", result);
    return 0;
    
}