#include "ft_strncpy.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char string_src[] = "Marjorie";
    char string_dest[] = "";

    char *string_src_ptr = &string_src[0];
    char *string_dest_ptr = &string_dest[0];

    char *strPtr = ft_strncpy(string_dest_ptr, string_src_ptr, 3);

    while(*strPtr != '\0')
    {
        write(1, strPtr, 1);
        strPtr++;
    }
    return 0;
    // printf("%d", string_dest);
    
}