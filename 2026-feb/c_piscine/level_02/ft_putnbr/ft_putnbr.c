/*
Turn-in directory: ex02/
Files to turn in: ft_putnbr.c
Allowed functions: write
• Create a function that displays the number passed as a parameter. The function
must be able to handle all possible values of the int type.
• The function should be prototyped as follows:
void ft_putnbr(int nb);
• Example usage:
◦ ft_putnbr(42) outputs "42".
*/

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    int div;

    div = 1;
    while (nb / div >= 10)
    {
        div = div * 10;
    }
    while (div > 0)
    {
        ft_putchar(nb / div % 10 + '0');
        div = div / 10;
    }
}

int main(void)
{
    ft_putnbr(42);
    return (0);
}