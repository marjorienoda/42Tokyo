/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 07:17:50 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 07:17:50 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    unsigned int n;
    unsigned int div;

    if (nb < 0)
    {
        ft_putchar('-');
        n = (unsigned int) (-nb);
    }
    else
    {
        n = (unsigned int)nb;
    }
    div = 1;
    while (n / div >= 10)
    {
        div = div * 10;
    }
    while (div > 0)
    {
        ft_putchar(n / div % 10 + '0');
        div = div /10;
    }
}

// int main(void)
// {
//     ft_putnbr(0);
//     return (0);
// }