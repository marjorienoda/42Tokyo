/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-22 07:17:37 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-22 07:17:37 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_comb(void)
{
    char c;
    char d;
    char u;

    c = '0';
    while (c <= '7')
    {
        d = c + 1;
        while(d <= '8')
        {
            u = d + 1;
            while (u <= '9')
            {
                ft_putchar(c);
                ft_putchar(d);
                ft_putchar(u);
                if(!(c == '7' && d == '8' && u == '9'))
                {
                    ft_putchar(',');
                    ft_putchar(' ');
                }
                u++;
            }
            d++;
        }
        c++;
    }

}

// int main(void)
// {
//     ft_print_comb();
//     return (0);
// }