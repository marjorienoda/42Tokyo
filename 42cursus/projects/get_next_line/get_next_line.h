#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
int ft_strlen(char *str);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *str1, char *str2);
void *ft_memcpy(void *dest, const void *src, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
#endif