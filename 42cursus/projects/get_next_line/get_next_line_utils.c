#include "get_next_line.h"

void ft_bzero(void *s, size_t n)
{
    unsigned char *str;
    size_t i;
    str = s;
    i = 0;
    while(i < n)
    {
        *str = '\0';
        str++;
        i++;
    }
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t total_size;

    if(nmemb != 0 && size > __SIZE_MAX__ / nmemb)
        return(NULL);
    total_size = size * nmemb;
    ptr = malloc(total_size);
    if(!ptr)
        return(NULL);
    ft_bzero(ptr, total_size);
    return(ptr);
}