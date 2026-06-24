/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:53:41 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/16 14:07:37 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_pos(t_node *stack)
{
	int		min_pos;
	int		i;
	long	min;

	i = 0;
	min_pos = 0;
	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

void	simple_strag(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	min_pos;
	int	size;

	while (*stack_a && stack_size(*stack_a) > 1)
	{
		min_pos = find_min_pos(*stack_a);
		size = stack_size(*stack_a);
		while (min_pos != 0)
		{
			if (min_pos <= size / 2)
				ra_op(stack_a, bench);
			else
				rra_op(stack_a, bench);
			min_pos = find_min_pos(*stack_a);
		}
		pb_op(stack_a, stack_b, bench);
	}
	while (*stack_b)
		pa_op(stack_a, stack_b, bench);
}
