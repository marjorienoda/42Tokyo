#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strjoin_len(char *str1, size_t str1_len, char *str2, size_t str2_len);
void				*ft_calloc(size_t nmemb, size_t size);
#endif