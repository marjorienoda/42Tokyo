/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:08:18 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 14:08:20 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*create_new_node(int nb)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = nb;
	new_node->index = -1;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_node	*init_stack_a(int argc, char **argv, int start)
{
	t_node	*stack_a;
	t_node	*new_node;
	long	nb;

	stack_a = NULL;
	while (start < argc)
	{
		nb = ft_atoil(argv[start]);
		new_node = create_new_node(nb);
		if (!new_node)
		{
			ft_free_stack(stack_a);
			return (NULL);
		}
		stack_add_bottom(&stack_a, new_node);
		start++;
	}
	return (stack_a);
}
