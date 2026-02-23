/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-17 01:53:41 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-17 01:53:41 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_size_arr(int min, int max)
{
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int	size_arr;
	int	*ptr_arr;
	int	i;

	size_arr = get_size_arr(min, max);
	ptr_arr = (int *)malloc(size_arr * sizeof(int));
	if (min >= max)
	{
		ptr_arr = NULL;
	}
	i = 0;
	while (i < size_arr)
	{
		ptr_arr[i] = min + i;
		i++;
	}
	return (ptr_arr);
}

// #include <stdio.h>

// // Protótipo da sua função
// int		*ft_range(int min, int max);

// void	verify_range(int min, int max)
// {
// 	int	*result;
// 	int	size;

// 	result = ft_range(min, max);
// 	size = max - min;
// 	printf("Input: min %d, max %d\n", min, max);
// 	if (min >= max)
// 	{
// 		if (result == NULL)
// 			printf("✅ PASSOU (Retornou NULL corretamente)\n");
// 		else
// 			printf("❌ FALHA \n ");
// 	}
// 	else
// 	{
// 		if (result == NULL)
// 		{
// 			printf("❌ FALHA (Malloc falhou ou retornou NULL indevidamente)\n");
// 		}
// 		else
// 		{
// 			printf("✅ Conteúdo: {");
// 			for (int i = 0; i < size; i++)
// 			{
// 				printf("%d", result[i]);
// 				if (i < size - 1)
// 					printf(", ");
// 			}
// 			printf("}\n");
// 			// Verificação lógica simples do primeiro e último elemento
// 			if (result[0] == min && result[size - 1] == max - 1)
// 				printf("✅ PASSOU (Valores corretos)\n");
// 			else
// 				printf("❌ FALHA (Valores incorretos)\n");
// 			free(result); // Limpeza obrigatória
// 		}
// 	}
// 	printf("------------------------------------------\n");
// }

// int	main(void)
// {
// 	printf("=== TESTANDO FT_RANGE ===\n\n");

// 	verify_range(5, 10);   // Caso comum
// 	verify_range(-3, 2);   // Com negativos
// 	verify_range(-10, -7); // Apenas negativos
// 	verify_range(0, 1);    // Apenas um elemento
// 	verify_range(5, 5);    // Min == Max (NULL)
// 	verify_range(10, 5);   // Min > Max (NULL)

// 	return (0);
// }