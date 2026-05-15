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
		counter += ft_putptr(va_arg(list, unsigned long long));
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

#include <limits.h>
#include <stdio.h>

void	print_header(char *title)
{
	printf("\n--- Teste: %s ---\n", title);
}

int	main(void)
{
	char	*str;

	// int		expected;
	// int		result;
	str = NULL;
	printf("%p \n", str);
	ft_printf("%p \n", str);
	// str = NULL;
	// print_header("%%d");
	// result = ft_printf("ac: %d\n", INT_MIN);
	// expected = printf("or: %d\n", INT_MIN);
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
	// print_header("%%u");
	// result = ft_printf("ac: %u\n", (unsigned int)INT_MIN);
	// expected = printf("or: %u\n", (unsigned int)INT_MIN);
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
	// print_header("%%s");
	// result = ft_printf("ac: [%s]\n", str);
	// expected = printf("or: [%s]\n", str);
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
	// print_header("%%x");
	// result = ft_printf("ac: %x\n", -1234567890);
	// expected = printf("or: %x\n", -1234567890);
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
	// print_header("%%X");
	// result = ft_printf("ac: %X\n", -1234567890);
	// expected = printf("or: %X\n", -1234567890);
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
	// print_header("%%c");
	// result = ft_printf("ac: %c\n", 'A');
	// expected = printf("or: %c\n", 'A');
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
	// print_header("%%");
	// result = ft_printf("ac: %%\n");
	// expected = printf("or: %%\n");
	// printf("Return value-> ft: %d | or: %d\n", result, expected);
}
