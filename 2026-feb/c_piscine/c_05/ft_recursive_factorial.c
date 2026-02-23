/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:38:25 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/12 14:38:50 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	if (nb < 0)
	{
		return (0);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>

// // Protótipo da sua função
// int		ft_recursive_factorial(int nb);

// void	verify_factorial(int nb, int expected)
// {
// 	int	result;

// 	result = ft_recursive_factorial(nb);
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
// 	printf("--- TESTANDO ft_recursive_factorial ---\n");
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
