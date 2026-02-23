/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:22:48 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/16 10:22:51 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_base_size(char *base)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

int	contains_dup_char(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0' && base[i] != base[j])
		{
			j++;
		}
		if (base[i] == base[j])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	contains_invalid_char(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	n;

	base_size = get_base_size(base);
	if (base_size == 0 || base_size == 1 || contains_dup_char(base) == 1
		|| contains_invalid_char(base) == 1)
	{
		return ;
	}
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= base_size)
	{
		ft_putnbr_base(n / base_size, base);
	}
	ft_putchar(base[n % base_size]);
}

// #include <unistd.h>

// void	ft_putnbr_base(int nbr, char *base);

// int	main(void)
// {
// 	// --- TESTES VÁLIDOS ---
// 	write(1, "Decimal (42): ", 14);
// 	ft_putnbr_base(42, "0123456789"); // Esperado: 42
// 	write(1, "\nBinary (42): ", 14);
// 	ft_putnbr_base(42, "01"); // Esperado: 101010
// 	write(1, "\nHexa (42): ", 12);
// 	ft_putnbr_base(42, "0123456789ABCDEF"); // Esperado: 2A
// 	write(1, "\nPoney (42): ", 13);
// 	ft_putnbr_base(42, "poneyvif"); // Esperado: vn

// 	// --- TESTE DE NEGATIVO E LIMITE ---
// 	write(1, "\nNegativo (-42): ", 17);
// 	ft_putnbr_base(-42, "0123456789"); // Esperado: -42
// 	write(1, "\nINT_MIN (-2147483648): ", 24);
// 	ft_putnbr_base(-2147483648, "0123456789"); // Esperado: -2147483648

// 	// --- TESTES INVÁLIDOS (Não devem imprimir nada após os dois pontos) ---
// 	write(1, "\nInvalido (duplicado): ", 23);
// 	ft_putnbr_base(42, "aba");
// 	write(1, "\nInvalido (sinal +): ", 21);
// 	ft_putnbr_base(42, "012+3");
// 	write(1, "\n", 1);

// 	return (0);
// }