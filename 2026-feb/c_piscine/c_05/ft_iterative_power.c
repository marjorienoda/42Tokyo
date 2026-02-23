/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <marjorie_yumie@hotmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:32:47 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/02/12 17:07:46 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	aux;
	int	result;

	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	aux = 1;
	result = 1;
	while (aux <= power)
	{
		result = result * nb;
		aux++;
	}
	return (result);
}

// #include <stdio.h>

// void	run_test(int nb, int power, int expected)
// {
// 	int	res;

// 	res = ft_iterative_power(nb, power);
// 	printf("[%d^%d] -> Esperado: %d | Obtido: %d", nb, power, expected, res);
// 	if (res == expected)
// 		printf(" | [ PASSOU ✅]\n");
// 	else
// 		printf(" | [ FALHOU ❌]\n");
// }

// int	main(void)
// {
// 	printf("--- Casos Padrão ---\n");
// 	run_test(2, 3, 8);
// 	run_test(5, 2, 25);
// 	run_test(3, 4, 81);

// 	printf("\n--- Edge Cases: Power 0 e 1 ---\n");
// 	run_test(10, 0, 1);  // Qualquer n ^ 0 = 1
// 	run_test(0, 0, 1);   // 0 ^ 0 deve ser 1 (padrão 42)
// 	run_test(42, 1, 42); // n ^ 1 = n

// 	printf("\n--- Edge Cases: Base 0, 1 e -1 ---\n");
// 	run_test(0, 5, 0);   // 0 elevado a qualquer positivo = 0
// 	run_test(1, 100, 1); // 1 elevado a qualquer coisa = 1
// 	run_test(-1, 2, 1);  // -1 ^ par = 1
// 	run_test(-1, 3, -1); // -1 ^ ímpar = -1

// 	printf("\n--- Edge Cases: Negativos e Limites ---\n");
// 	run_test(5, -2, 0);             // Power negativo retorna 0
// 	run_test(-2, 3, -8);            // Base negativa
// 	run_test(46340, 2, 2147395600); // Próximo ao limite do INT_MAX

// 	return (0);
// }