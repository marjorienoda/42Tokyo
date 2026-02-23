/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-17 01:53:50 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026-02-17 01:53:50 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_lenght_str(char *src)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (src[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*ptr_dest;
	int		size_str;

	size_str = ft_lenght_str(src);
	ptr_dest = (char *)malloc((size_str + 1) * sizeof(char));
	return (ft_strcpy(ptr_dest, src));
}

// #include <stdio.h>
// #include <string.h>

// // Protótipo da sua função char *ft_strdup(char *src);

// void	verify_strdup(char *src)
// {
// 	char	*result;
// 	int		content_ok;

// 	result = ft_strdup(src);
// 	// 1. Verificar se a alocação falhou (Proteção contra Malloc NULL)
// 	if (result == NULL)
// 	{
// 		printf("❌ FALHA | Malloc retornou NULL para: \"%s\"\n", src);
// 		return ;
// 	}
// 	// 2. Comparações lógicas
// 	content_ok = (strcmp(result, src) == 0);
// 	int address_ok = (result != src); // Deve ser um novo endereço no Heap
// 	// 3. Impressão dos resultados e do conteúdo
// 	if (content_ok && address_ok)
// 	{
// 		printf("✅ PASSOU\n");
// 		printf("   Conteúdo: [%s]\n", result);
// 		printf("   Endereço: %p (Original era %p)\n", (void *)result,
// 			(void *)src);
// 	}
// 	else
// 	{
// 		printf("❌ FALHA\n");
// 		printf("   Conteúdo Obtido: [%s]\n", result);
// 		if (!address_ok)
// 			printf("ERRO: O endereço de memória é o mesmo \n");
// 		if (!content_ok)
// 			printf("   ERRO: O conteúdo não é idêntico ao original.\n");
// 	}
// 	printf("--------------------------------------------------\n");
// 	// Limpeza obrigatória de memória alocada
// 	free(result);
// }

// int	main(void)
// {
// 	printf("=== TESTANDO FT_STRDUP ===\n\n");
// 	verify_strdup("42 Brasil");
// 	verify_strdup("");
// 	verify_strdup("String com\nquebra e\t-tab-");
// 	verify_strdup("!@#$%^&*()_+-=[]{}|;':\",./<>?");
// 	return (0);
// }
