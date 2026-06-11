#include "../push_swap.h"
#include <stdio.h>

int ft_putdouble_fd(double n, int fd)
{
    int integer_part;
    int decimal_part;
    int counter;

	counter = 0;
    integer_part = (int)n;
    decimal_part = (int)((n - integer_part) * 100);
	counter += ft_putnbr_fd(integer_part, fd);
	counter +=ft_putchar_fd('.', fd);
	if (decimal_part < 10)
        counter += ft_putchar_fd('0', fd);
    counter += ft_putnbr_fd(decimal_part, fd);
    return(counter);
}