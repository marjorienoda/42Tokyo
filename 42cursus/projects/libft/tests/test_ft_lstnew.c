#include "tests.h"
#include <stdio.h>


void	test_ft_lstnew(void)
{
	printf("--- Testando ft_lstnew ---\n");

	// Caso 1: Testando com uma string
	char	*str_content = "Marjorie 42";
	t_list	*node1 = ft_lstnew(str_content);

	if (node1)
	{
		printf("Teste 1 (String): ");
		if (node1->content == str_content && node1->next == NULL)
			printf("✅ SUCESSO\n");
		else
			printf("❌ FALHA (Conteúdo ou Next incorretos)\n");
		free(node1); // Não esqueça de liberar a memória alocada pelo seu ft_lstnew
	}
	else
		printf("❌ FALHA (Erro de alocação/Malloc)\n");

	// Caso 2: Testando com um ponteiro para inteiro
	int		num = 42;
	t_list	*node2 = ft_lstnew(&num);

	if (node2)
	{
		printf("Teste 2 (Inteiro): ");
		if (*(int *)(node2->content) == 42)
			printf("✅ SUCESSO\n");
		else
			printf("❌ FALHA (Valor do inteiro incorreto)\n");
		free(node2);
	}

	// Caso 3: Testando com conteúdo NULL
	t_list	*node3 = ft_lstnew(NULL);

	if (node3)
	{
		printf("Teste 3 (Content NULL): ");
		if (node3->content == NULL && node3->next == NULL)
			printf("✅ SUCESSO\n");
		else
			printf("❌ FALHA\n");
		free(node3);
	}

	printf("--------------------------\n");
}