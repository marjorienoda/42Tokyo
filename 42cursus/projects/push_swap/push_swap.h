#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef enum e_strategy
{
    ADAPTIVE,
    SIMPLE,
    MEDIUM,
    COMPLEX
} t_strategy;

/*
	====== LIBFT ======
*/

long    ft_atoil(const char *str);
int     ft_isdigit(int c);
void    ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/*
	====== UTILS ======
*/

void ft_error(char *str);
void is_valid_input(int argc, char **argv);
int get_start_pos(int argc, char **argv);

#endif