/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:09:13 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:09:15 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	div;
	int				counter;

	counter = 0;
	if (n < 0)
	{
		counter += ft_putchar_fd('-', fd);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	div = 1;
	while (nb / div >= 10)
		div = div * 10;
	while (div > 0)
	{
		counter += ft_putchar_fd((nb / div % 10) + '0', fd);
		div = div / 10;
	}
	return (counter);
}
