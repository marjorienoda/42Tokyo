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

#include "../ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned int	base_size;
	int				counter;

	base_size = ft_strlen(base);
	counter = 0;
	if (nb >= base_size)
		counter += ft_putnbr_base(nb / base_size, base);
	counter += ft_putchar(base[nb % base_size]);
	return (counter);
}
