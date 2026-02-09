#include "ft_str_is_uppercase.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char string_src[] = "123mozinho";

    char *string_src_ptr = &string_src[0];

    int result = ft_str_is_uppercase(string_src_ptr);

    printf("%d", result);
    return 0;
    
}