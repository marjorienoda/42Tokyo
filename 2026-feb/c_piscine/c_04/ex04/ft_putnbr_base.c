#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int get_base_size(char *base)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(base[i] != '\0')
    {
        i++;
        count++;
    }
    return (count);
}

int contains_dup_char(char *base)
{
    int i;
    int j;
    i = 0;

    while(base[i] != '\0')
    {
        j = i + 1;
        while(base[j] != '\0' && base[i] != base[j])
        {
            j++;
        }
        if (base[i] == base[j])
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int contains_invalid_char(char *base)
{
    int i;
    i = 0;

    while(base[i] != '\0')
    {
        if (base[i] == '+' || base[i] == '-')
        {
            return (1);
        }
        i++;
    }
    return (0);
}


void ft_putnbr_base(int nbr, char *base)
{
    int base_size;
    long n;

    base_size = get_base_size(base);

    if (base_size == 0 || base_size == 1 ||
        contains_dup_char(base) == 1 || contains_invalid_char(base) == 1)
    {
        return;
    }

    n = nbr;
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    if (n >= base_size)
    {
        ft_putnbr_base(n / base_size, base);
    }
    ft_putchar(base[n % base_size]);
}

int main(void)
{
    char str[] = "poneyvif";
    char *ptr;
    ptr = str;

    ft_putnbr_base(-10, ptr);
}