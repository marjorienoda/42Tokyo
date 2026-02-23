/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-17 01:52:57 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-17 01:52:57 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*array;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(size * sizeof(int));
	if (array == NULL)
	{
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (size);
}

// #include <stdio.h>

// // Protótipo da sua função
// int		ft_ultimate_range(int **range, int min, int max);

// void	run_test(int min, int max, int test_id)
// {
// 	int	size;
// 	int	expected_size;
// 	int	i;
// 	int	ok;

// 	int *ptr = (void *)0; // Inicializa com um valor nulo
// 	size = ft_ultimate_range(&ptr, min, max);
// 	printf("Teste %d: [%d, %d)\n", test_id, min, max);
// 	printf("  - Tamanho retornado: %d\n", size);
// 	// Requisito: Se min >= max, range deve ser NULL e retornar 0
// 	if (min >= max)
// 	{
// 		if (size == 0 && ptr == NULL)
// 			printf("  - Resultado: ✅ PASSOU (Tamanho 0 e ponteiro NULL)\n");
// 		else
// 			printf("  - Resultado: ❌ FALHOU (Esperava 0 e NULL)\n");
// 	}
// 	// Requisito: Erro de alocação (Malloc retornando NULL)
// 	else if (size == -1)
// 	{
// 		printf("  - Resultado: ⚠️ Malloc falhou ou erro interno.\n");
// 	}
// 	// Requisito: Sucesso (Min < Max)
// 	else
// 	{
// 		expected_size = max - min;
// 		if (size != expected_size)
// 		{
// 			printf("  - Resultado: ❌ FALHOU Esperado:% d)\n ", expected_size);
// 			return ;
// 		}
// 		i = 0;
// 		ok = 1;
// 		while (i < size)
// 		{
// 			if (ptr[i] != min + i)
// 			{
// 				ok = 0;
// 				break ;
// 			}
// 			i++;
// 		}
// 		if (ok)
// 			printf("  - Resultado: ✅ PASSOU (Valores corretos na memória)\n");
// 		else
// 			printf("  - Resultado: ❌ FALHOU (Valores incorretos no array)\n");
// 		free(ptr); // Libera a memória alocada pela sua função
// 	}
// 	printf("------------------------------------\n");
// }

// int	main(void)
// {
// 	run_test(5, 10, 1); // Caso comum
// 	run_test(-2, 2, 2); // Números negativos
// 	run_test(10, 5, 3); // Min > Max (Deve ser NULL e size 0)
// 	run_test(7, 7, 4);  // Min == Max (Deve ser NULL e size 0)
// 	run_test(0, 1, 5);  // Apenas um elemento
// 	return (0);
// }