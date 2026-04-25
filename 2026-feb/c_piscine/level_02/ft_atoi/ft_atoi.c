/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/
#include <stdio.h>
int ft_sign_number (const char *str)
{
    int i;
    int sign;
    
    i = 0;
    sign = 1;
    while(str[i] != '\0')
    {
        if (str[i] == '-')
        {
            sign = sign * - 1;
        }
        i++;
    }
    return (sign);
}

int	ft_atoi(const char *str)
{
    int i;
    int nb;
    int sign;


    i = 0;
    nb = 0;
    sign = ft_sign_number(str);
    while(str[i] == '-')
    {
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <='9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb * sign);
}



int main (void)
{
    char str[] = "-42";
    printf("%d", ft_atoi(str));
    return (0);
}