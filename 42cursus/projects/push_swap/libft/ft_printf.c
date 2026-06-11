/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:08:29 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/11 12:08:31 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdarg.h>

static int	print_format(va_list list, char s, int fd)
{
	int	counter;

	counter = 0;
	if (s == 'c')
		counter += ft_putchar_fd(va_arg(list, int), fd);
	if (s == 's')
		counter += ft_putstr_fd(va_arg(list, char *), fd);
	if (s == 'd' || s == 'i')
		counter += ft_putnbr_fd(va_arg(list, int), fd);
	if (s == 'f')
		counter += ft_putdouble_fd(va_arg(list, double), fd);
	if (s == '%')
		counter += ft_putchar_fd('%', fd);
	return (counter);
}

int	ft_printf(const char *str, int fd, ...)
{
	va_list	list;
	int		i;
	int		counter;

	va_start(list, fd);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			counter += print_format(list, str[i], fd);
		}
		else
			counter += ft_putchar_fd(str[i], fd);
		i++;
	}
	va_end(list);
	return (counter);
}
