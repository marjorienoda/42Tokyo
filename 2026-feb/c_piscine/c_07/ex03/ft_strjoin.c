#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    return(dest + i);
}

int ft_total_size(int size, char **strs, int sep_len)
{
    int i;
    int total;

    total = 0;
    i = 0;
    while (i < size)
    {
        total += ft_strlen(strs[i]);
        if (i < size - 1)
        {
            total += sep_len;
        }
        i++;
    }
    return (total);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int total_size;
    char *dest;
    char *curr;

    if (size <= 0)
    {
        dest = (char *) malloc(sizeof(char));
        if (dest != NULL)
            *dest = '\0';
        return (dest);
    }
    total_size = ft_total_size(size, strs, ft_strlen(sep));
    dest = (char *) malloc(sizeof(char) * (total_size + 1));
    if (dest == NULL)
        return (NULL);
    curr = dest;
    i = 0;
    while (i < size)
    {
        curr = ft_strcpy(curr, strs[i]);
        if (i < size - 1)
            curr = ft_strcpy(curr, sep);
        i++;
    }
    *curr = '\0';
    return (dest);
}

#include <stdio.h>
int main(void)
{
    char *resultado;
    char *str[] = {"Ola"};
    char *separador = ",";

    resultado = ft_strjoin(1, str, separador);
    printf("%s", resultado);
    free(resultado);
}