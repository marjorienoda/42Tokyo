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
	if (s == 'd' || s == 'i')
		counter += ft_putnbr(va_arg(list, int));
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

#include <stdio.h>

int	main(void)
{
	int result = ft_printf("Ola %c, %s, %i \n", 'c', "Marjorie!@", -21474836);
	int expected = printf("Ola %c, %s, %i \n", 'c', "Marjorie!@", -21474836);

	printf("%d \n", result);
	printf("%d \n", expected);
	return (0);
}