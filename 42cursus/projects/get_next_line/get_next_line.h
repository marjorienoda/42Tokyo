#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char *get_next_line(int fd);
void ft_bzero(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
#endif