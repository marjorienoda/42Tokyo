/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:13 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:52:15 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*node_to_move;

	if (!*stack_b)
		return ;
	node_to_move = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	if (!*stack_a)
	{
		first_node(node_to_move);
		node_to_move->prev = NULL;
		node_to_move->next = NULL;
		(*stack_a) = node_to_move;
	}
	else
	{
		node_to_move->prev = NULL;
		node_to_move->next = *stack_a;
		(*stack_a)->prev = node_to_move;
		*stack_a = node_to_move;
	}
	if (bench)
	{
		bench->pa_ops++;
		bench->total_ops++;
	}
	ft_printf("pa\n", 1);
}
