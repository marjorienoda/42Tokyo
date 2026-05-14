/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 18:01:44 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/14 18:01:46 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(int nb, char *base)
{
	unsigned int base_size;
	unsigned int n;
	int counter;

	base_size = ft_strlen(base);
	n = nb;
	counter = 0;
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n >= base_size)
	{
		counter += ft_putnbr_base(n / base_size, base);
	}
	counter += ft_putchar(base[n % base_size]);
	return (counter);
}