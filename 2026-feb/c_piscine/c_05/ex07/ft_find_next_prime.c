int ft_is_prime(int nb)
{
    int i;

    if (nb == 0 || nb == 1 || nb < 0)
    {
        return (0);
    }

    i = nb - 1;
    while (i > 1 && nb % i != 0)
    {
        i--;
    }

    if (i == 1)
        return (1);
    else
        return (0);
}

int ft_find_next_prime(int nb)
{
    while(ft_is_prime(nb) != 1)
    {
        nb++;
    }
    return (nb);
}

// #include <stdio.h>

// int main(void)
// {
//     int result = ft_find_next_prime(2147483648);
//     printf("result: %d", result);
// }