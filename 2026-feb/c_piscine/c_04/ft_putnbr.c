/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:52:20 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/13 10:52:23 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;
	unsigned int	div;

	if (nb < 0)
	{
		ft_putchar('-');
		n = (unsigned int)(-nb);
	}
	else
	{
		n = (unsigned int)nb;
	}
	div = 1;
	while (n / div >= 10)
	{
		div = div * 10;
	}
	while (div > 0)
	{
		ft_putchar(n / div % 10 + '0');
		div = div / 10;
	}
}

// #include <limits.h>
// #include <stdio.h>

// // Protótipo da sua função
// void	ft_putnbr(int nb);

// void	run_test(int nb, char *expected)
// {
// 	printf("[Teste]: n = %d | Esperado: %s | Obtido: ", nb, expected);
// 	fflush(stdout); // Garante que o printf apareça antes do ft_putnbr
// 	ft_putnbr(nb);
// 	printf("\n");
// }

// int	main(void)
// {
// 	printf("=== INICIANDO TESTES FT_PUTNBR ===\n\n");

// 	run_test(42, "42");
// 	run_test(0, "0");
// 	run_test(-5, "-5");
// 	run_test(123456789, "123456789");
// 	run_test(-2147483647, "-2147483647");

// 	// O teste decisivo:
// 	run_test(INT_MIN, "-2147483648");

// 	// O limite superior:
// 	run_test(INT_MAX, "2147483647");

// 	printf("\n=== FIM DOS TESTES ===\n");
// 	return (0);
// }