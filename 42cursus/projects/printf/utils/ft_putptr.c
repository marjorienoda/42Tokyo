/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:01:12 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/15 18:03:45 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void	ft_putlong_base(unsigned long long ptr, char *base,
		unsigned long long base_size)
{
	if (ptr >= base_size)
	{
		ft_putlong_base(ptr / base_size, base, base_size);
	}
	ft_putchar(base[ptr % base_size]);
}

int	ft_putptr(unsigned long long ptr, char *base)
{
	int					counter;
	unsigned long long	base_size;

	counter = 0;
	base_size = ft_strlen(base);
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	ft_putlong_base(ptr, base, base_size);
	while (ptr >= base_size)
	{
		ptr /= base_size;
		counter++;
	}
	counter++;
	return (counter);
}
