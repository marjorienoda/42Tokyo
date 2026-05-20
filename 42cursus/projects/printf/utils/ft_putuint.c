/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:00:28 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/15 17:00:44 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putuint(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
		counter += ft_putuint(nb / 10);
	counter += ft_putchar((nb % 10) + '0');
	return (counter);
}
