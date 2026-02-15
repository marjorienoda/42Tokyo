#include <stdio.h>

char *ft_first_char(char *str)
{
    while (*str == ' ')
    {
        str++;
    }
    return (str);
}

int ft_number_sign(char *str)
{
    int i;
    int sign;
    i = 0;
    sign = 1;

    while (str[i] != '\0')
    {
        if (str[i] == '-')
        {
            sign = sign * - 1;
        }
        i++;
    }
    return (sign);
}

int ft_atoi(char *str)
{
    long nb;
    int sign;

    nb = 0;
    sign = ft_number_sign(str);

    while (*str == '-' || *str == '+')
    {
        str++;
    }

    while (*str >= '0' && *str <= '9')
    {
        nb = nb * 10 + (*str - '0');
        str++;
    }
    return (nb * sign);
}


int main(void)
{
    char str []= " ---+---+1234ab567";
    char *ptr;
    int result;
    char *str_ptr;

    ptr = str;
    str_ptr = ft_first_char(ptr);
    result = ft_atoi(str_ptr);
    printf("result: %d", result);
}