#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    i =  0;
    while(str[i] != '\0')
        i++;
    return(i);
}

char *ft_strchr(const char *s, int c)
{
    char *str;
    str = (char *)s;
    while(*str != c)
    {
        if(*str == '\0')
            return(NULL);
        str++;
    }
    return(str);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_s;
    const unsigned char *src_s;
    size_t i;

    dest_s = (unsigned char *)dest;
    src_s = (const unsigned char *)src;
    if(!dest || !src)
        return(NULL);
    i = 0;
    while(i < n)
    {
        dest_s[i] = src_s[i];
        i++;
    }
    return(dest);
}

char *ft_strjoin(char *str1, char *str2)
{
    char *ptr;
    size_t str1_len;
    size_t str2_len;

    str1_len = ft_strlen(str1);
    str2_len = ft_strlen(str2);
    ptr = malloc(sizeof(char) * (str1_len + str2_len + 1));
    if(!ptr)
        return(NULL);
    ft_memcpy(ptr, str1, str1_len);
    ft_memcpy(ptr + str1_len, str2, str2_len);
    ptr[str1_len + str2_len] = '\0';
    return(ptr);
}

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    unsigned char *p;
    size_t total_size;
    size_t i;

    if(nmemb != 0 && size > __SIZE_MAX__ / nmemb)
        return(NULL);
    total_size = size * nmemb;
    ptr = malloc(total_size);
    if(!ptr)
        return(NULL);
    i = 0;
    p = ptr;
    while(i < total_size)
    {
        p[i++] = 0;
    }
    return(ptr);
}