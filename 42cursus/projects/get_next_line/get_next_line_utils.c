#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
    size_t i;
    i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}

char				*ft_strchr(const char *s, int c)
{
    unsigned char *str;
    unsigned char ch;

    str = (unsigned char *)s;
    ch = (unsigned char)c;
	if(!s)
		return(NULL);
    while(*str != ch)
    {
        if(*str == '\0')
            return(NULL);
        str++;
    }
    return((char *)str);
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *dest_s;
    const unsigned char *src_s;
    size_t i;

    dest_s = (unsigned char*)dest;
    src_s = (const unsigned char *)src;
    i = 0;
    while(i < n)
    {
        dest_s[i] = src_s[i];
        i++;
    }
    return(dest);
}

char *ft_strjoin_len(char *str1, size_t str1_len, char *str2, size_t str2_len)
{
    char    *ptr;

    ptr = malloc(str1_len + str2_len + 1);
    if(!ptr)
    {
        free(str1);
        return(NULL);
    }
    ft_memcpy(ptr, str1, str1_len);
    ft_memcpy(ptr + str1_len, str2, str2_len + 1);
    free(str1);
    return(ptr);
}


void				*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	unsigned char *p;
	size_t total_size;
	size_t i;

	if(nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return(NULL);
	total_size = nmemb * size;
	ptr = malloc(sizeof(char) * total_size);
	if(!ptr)
		return(NULL);
	p = ptr;
	i = 0;
	while(i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return(ptr);
}