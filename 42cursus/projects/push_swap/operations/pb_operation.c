/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:52:21 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 13:52:23 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_op(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*node_to_move;

	if (!*stack_a)
		return ;
	node_to_move = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	push_to_top(stack_b, node_to_move);
	if (bench)
	{
		bench->pb_ops++;
		bench->total_ops++;
	}
	ft_printf("pb\n", 1);
}
