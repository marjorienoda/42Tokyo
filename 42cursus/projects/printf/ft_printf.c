/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:39:01 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/05/13 10:39:02 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	print_format(va_list list, char s)
{
	int	counter;

	counter = 0;
	if (s == 'c')
		counter += ft_putchar(va_arg(list, int));
	if (s == 's')
		counter += ft_putstr(va_arg(list, char *));
	if (s == 'p')
		counter += ft_putptr(va_arg(list, unsigned long long),
				"0123456789abcdef");
	if (s == 'd' || s == 'i')
		counter += ft_putnbr(va_arg(list, int));
	if (s == 'u')
		counter += ft_putuint(va_arg(list, unsigned int));
	if (s == 'x')
		counter += ft_putnbr_base(va_arg(list, unsigned int),
				"0123456789abcdef");
	if (s == 'X')
		counter += ft_putnbr_base(va_arg(list, unsigned int),
				"0123456789ABCDEF");
	if (s == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		counter;

	va_start(list, str);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			counter += print_format(list, str[i]);
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (counter);
}
