/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoda-ta <mnoda-ta@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:50:18 by mnoda-ta          #+#    #+#             */
/*   Updated: 2026/06/19 15:50:19 by mnoda-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index_stack(t_node *stack_a, int size)
{
	int	*temp_array;

	temp_array = create_array_tmp(stack_a, size);
	temp_array = bubble_sort(temp_array, size);
	fill_index_stack(stack_a, temp_array, size);
	free(temp_array);
}

void	complex_strag(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*stack_a);
	index_stack(*stack_a, size);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra_op(stack_a, bench);
			else
				pb_op(stack_a, stack_b, bench);
			j++;
		}
		while (*stack_b)
			pa_op(stack_a, stack_b, bench);
		i++;
	}
}
