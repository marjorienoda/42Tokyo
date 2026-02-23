#include <unistd.h>

void ft_putchar (char c)
{
    write(1, &c, 1);
}

void ft_putnbr_n (int nb, int n)
{
    int div;
    int temp_n;

    div = 1;
    temp_n = n;
    while (--temp_n > 0)
    {
        div = div * 10;
    }
    while (div > 0)
    {
        ft_putchar((nb / div) % 10 + '0');
        div = div / 10;
    }
}

int ft_is_valid(int nb, int n)
{
    int prev_digit;
    int i;
    int current_digit;

    prev_digit = 10;
    i = 0;
    while (i < n)
    {
        current_digit = nb % 10;
        if (current_digit >= prev_digit)
            return (0);
        prev_digit = current_digit;
        nb = nb /10;
        i++;
    }
    return (1);
}

void ft_print_combn(int n)
{
    int i;
    int max;
    int last_printed;
    if (n <= 0 || n >= 10)
    {
        return ;
    }
    i = 0;
    max = 0;
    while (i < n)
    {
        max = max * 10 + (9 - n + 1 + i);
        i++;
    }
    last_printed = max;
    i = 0;
    while (i <= max)
    {
        if(ft_is_valid(i, n))
        {
            ft_putnbr_n(i, n);
            if(i != last_printed)
            {
                write(1, ", ", 2);
            }
        }
        i++;
    }
}


// int main(void)
// {
//     ft_print_combn(2);
//     return (0);
// }