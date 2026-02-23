/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:09:19 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/17 09:06:42 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb == 1)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	result = 1;
	while (nb > 0)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}

// #include <stdio.h>

// // Protótipo da sua função
// int		ft_iterative_factorial(int nb);

// void	verify_factorial(int nb, int expected)
// {
// 	int	result;

// 	result = ft_iterative_factorial(nb);
// 	if (result == expected)
// 	{
// 		printf("✅ PASSOU | nb: %d | Resultado: %d\n", nb, result);
// 	}
// 	else
// 	{
// 		printf("❌ FALHOU | nb: %d | Esperado: %d | Obtido: %d\n", nb, expected,
// 			result);
// 	}
// }

// int	main(void)
// {
// 	printf("--- TESTANDO FT_ITERATIVE_FACTORIAL ---\n");
// 	// Casos Inválidos
// 	verify_factorial(-1, 0);
// 	verify_factorial(-10, 0);
// 	// Casos Base
// 	verify_factorial(0, 1);
// 	verify_factorial(1, 1);
// 	// Casos Comuns
// 	verify_factorial(2, 2);
// 	verify_factorial(3, 6);
// 	verify_factorial(5, 120);
// 	verify_factorial(10, 3628800);
// 	return (0);
// }
