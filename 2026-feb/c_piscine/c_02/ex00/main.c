#include "ft_strcpy.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char string_src[] = "Hello";
    char string_dest[] = "";

    char *string_src_ptr = &string_src[0];
    char *string_dest_ptr = &string_dest[0];

    ft_strcpy(string_dest_ptr, string_src_ptr);

    while(*string_dest_ptr != '\0')
    {
        write(1, string_dest_ptr, 1);
        string_dest_ptr++;
    }
    return 0;
    // printf("%d", string_dest);
    
}