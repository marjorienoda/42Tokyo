/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:36:23 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/14 16:36:25 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	unsigned int n;
	unsigned int div;
	int counter;

	counter = 0;
	if (nb < 0)
	{
		counter += ft_putchar('-');
		n = (unsigned int)(nb * -1);
	}
	else
		n = (unsigned int)nb;
	div = 1;
	while (n / div >= 10)
		div *= 10;
	while (div > 0)
	{
		counter += ft_putchar((n / div % 10) + '0');
		div /= 10;
	}
	return (counter);
}