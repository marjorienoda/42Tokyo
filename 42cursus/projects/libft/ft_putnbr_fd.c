/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 11:16:00 by marvin            #+#    #+#             */
/*   Updated: 2026/05/04 11:16:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    unsigned int nb;
    unsigned int div;

    if(n < 0)
    {
        ft_putchar_fd('-', fd);
        nb = (unsigned int) (n * -1);
    }
    else
        nb = (unsigned int) n;
    div = 1;
    while(nb / div > 10)
        div = div * 10;
    while(div > 0)
    {
        ft_putchar_fd((nb / div % 10) + '0', fd);
        div = div / 10;
    }
}